#include <bits/stdc++.h>

using namespace std;

// suffix array
const int N = 1e6 + 5;
char s[N];
int sa[N], pos[N], lcp[N], tmp[N], gap, n;

bool cmp_sa(int a, int b) {
  if(pos[a] - pos[b])
    return pos[a] < pos[b];
  a += gap; b += gap;
  return (a < n && b < n) ? pos[a] < pos[b] : a > b;
}

void build_sa() {
  for(int i = 0; i<n; i++)
    sa[i] = i, pos[i] = s[i];
  for(gap = 1;; gap <<= 1) {
    sort(sa, sa + n, cmp_sa);
    for(int i = 1; i<n; i++) tmp[i] = tmp[i-1] + cmp_sa(sa[i-1], sa[i]);
    for(int i = 0; i<n; i++) pos[sa[i]] = tmp[i];
    if(tmp[n-1] == n-1) break;
  }
}

void build_lcp() {
  for(int i = 0, k = 0; i<n; i++) if(pos[i] - n + 1) {
    for(int j = sa[pos[i] + 1]; s[j + k] == s[i + k]; k++);
    lcp[pos[i]] = k;
    if(k) k--;
  }
}
int pal[N];
int sp[20][N];
int gets(int l, int r) {
  if (r <= l) return N;
  int len = r-l;
  int lg = 31-__builtin_clz(len);
  return min(sp[lg][l], sp[lg][r-(1<<lg)]);
}
int seg[N << 2];
void build(int id = 1, int l = 0, int r = n) {
  seg[id] = 0;
  if (r-l < 2) return;
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
}
void upd(int x, int val, int id = 1, int l = 0, int r = n) {
  if (r-l < 2) {
    seg[id] = val;
    return;
  }
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  if (x < mid)
    upd(x, val, il, l, mid);
  else
    upd(x, val, ir, mid, r);
  seg[id] = max(seg[il], seg[ir]);
}
int get(int x, int y, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return 0;
  if (x <= l && r <= y) return seg[id];
  int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
  return max(get(x, y, il, l, mid), get(x, y, ir, mid, r));
}
int main() {
  scanf("%d", &n);
  scanf("%s", s);
  reverse(s, s+n);
  build_sa();
  build_lcp();
  fill(pal, pal+n, 1);
  vector< vector<int> > p(2, vector<int>(n,0)); //p[1][i] even, p[0][i] odd palindrom center i
  for (int z=0, l=0, r=0; z < 2; z++, l=0, r=0)
    for (int i = 0; i < n; i++) {
      if (i < r) p[z][i] = min(r-i+!z, p[z][l+r-i+!z]);
      int L = i-p[z][i], R = i+p[z][i]-!z;
      pal[L] = max(pal[L], R-L+1);
      while (L-1 >= 0 && R+1 < n && s[L-1] == s[R+1]) {
        p[z][i]++, L--, R++;
        pal[L] = max(pal[L], R-L+1);
      }
       if(R > r) l = L,r = R;
    }
  int rr = 0;
  for (int i = 0; i < n; i++, rr--) {
    rr = max(rr, i+pal[i]-1);
    pal[i] = max(pal[i], rr-i+1);
  }
  for (int i = 0; i < n-1; i++) {
    sp[0][i] = lcp[i];
  }
  for (int i = 0; i + 1 < 20; i++) {
    for (int j = 0; j + (1 << (i+1)) < n; j++)
      sp[i+1][j] = min(sp[i][j], sp[i][j+(1<<i)]);
  }
  long long ans = 0;
  build();
  for (int i = n-1; i >= 0; i--) {
    int used = 0;
    int l = pos[i], r = n-1;
    while (l < r) {
      int mid = (l + r) / 2;
      int lc = gets(pos[i], mid), val = get(pos[i], mid+1);
      used = max(used, min(lc, val));
      if (lc > val)
        l = mid+1;
      else
        r = mid;
    }
    used = max(used, min(gets(pos[i], l), get(pos[i], l+1)));
    if (l > pos[i])
      used = max(used, min(gets(pos[i], l-1), get(pos[i], l)));
    l = 0, r = pos[i];
    while (l < r) {
      int mid = (l + r + 1) / 2;
      int lc = gets(mid, pos[i]), val = get(mid, pos[i]);
      used = max(used, min(lc, val));
      if (lc > val)
        r = mid-1;
      else
        l = mid;
    }
    used = max(used, min(gets(l, pos[i]), get(l, pos[i])));
    if (l < pos[i])
      used = max(used, min(gets(l+1, pos[i]), get(l+1, pos[i])));
    ans += max(0, pal[i]-used);
    upd(pos[i], pal[i]);
    printf("%lld\n", ans);
  }
  return 0;
}