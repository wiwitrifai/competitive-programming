#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int LN = 18;
const int M = N * 8 * 18;
const int mod = 1e9 + 7;
const int base = 1e5 + 1;

// Suffix array ans LCP
char s[N];
int sa[N], pos[N], lcp[N], tmp[N], gap, n;
int sparse[LN][N];

// Precomp task
long long ans[N], sum[N], inv[N], cnt[N], sumpal[N], sumpal2[N];

// Manacher algorithm
int pal[N + N], p[2][N];


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
  lcp[n-1] = 0;
}

int get_rmq(int l, int r) {
  int len = r-l+1;
  int ln = 31 - __builtin_clz(len);
  // assert(len >= (1<<ln) && len < (1<<(ln+1)));
  int a = sparse[ln][l], b = sparse[ln][r-(1<<ln)+1];
  return lcp[a] <= lcp[b] ? a : b;
}

long long powmod(long long b, long long pw) {
  long long ret = 1;
  while (pw) {
    if (pw & 1)
      ret = (ret * b) % mod;
    b = (b * b) % mod;
    pw >>= 1;
  }
  return ret;
}
long long calc(int l, int r) {
  long long ret = (sum[r] - sum[l]) % mod;
  ret = (ret * inv[l]) % mod;
  if (ret < 0)
    ret += mod;
  return ret;
}

// Persistent Segment Tree
struct node
{
  int l = 0, r = 0, val = 0;
  node() {
  }
  node (int l, int r, int v) : l(l), r(r), val(val) {
  }  
} seg[M];
int m, tmpstmp, root[N + N];

int build(int l = 0, int r = m) {
  int id = ++tmpstmp; 
  seg[id].val = 0;
  if (r-l < 2)
    return id;
  int mid = (l + r) >> 1;
  seg[id].l = build(l, mid);
  seg[id].r = build(mid, r);
  return id;
}

int upd(int x, int v, int id, int l = 0, int r = m) {
  int ID = ++tmpstmp;
  seg[ID].val = seg[id].val + v;
  seg[ID].l = seg[id].l;
  seg[ID].r = seg[id].r;
  if (r-l < 2) {
    return ID;
  }
  int mid = (l+r) >> 1;
  if (x < mid) {
    seg[ID].l = upd(x, v, seg[id].l, l, mid);
  }
  else {
    seg[ID].r = upd(x, v, seg[id].r, mid, r);
  }
  return ID;
}

int get(int x, int id, int l = 0, int r = m) {
  if (x >= r)
    return 0;
  if (x <= l)
    return seg[id].val;
  int mid = (l+r)>>1;
  return get(x, seg[id].l, l, mid) + get(x, seg[id].r, mid, r);
}

int main() {
  int q;
  scanf("%d %d", &n, &q);
  scanf("%s", s);
  sum[0] = 0;
  long long mul = 1;
  for (int i = 0; i < n; i++) {
    sum[i+1] = (sum[i] + mul * s[i]) % mod;
    mul = (mul * base) % mod;
    inv[i] = powmod(base, mod-1-i);
  }

  for(int z=0,l=0,r=0;z<2;z++,l=0,r=0)
      for(int i=0;i<n;i++)
      {
          if(i<r) p[z][i]=min(r-i+!z,p[z][l+r-i+!z]);
          int L=i-p[z][i], R=i+p[z][i]-!z;
          while(L-1>=0 && R+1<n && s[L-1]==s[R+1]) p[z][i]++,L--,R++;
          if(R>r) l=L,r=R;
      }
  for (int i = 0; i < n; i++) {
    pal[i + i] = p[0][i] * 2;
    pal[i + i + 1] = p[1][i] * 2 + 1;
  }
  m = 2 * n + 1;
  tmpstmp = 0;
  int root_now = build();
  for (int i = 0; i < m; i++) {
    if (pal[i]) {
      root_now = upd(i, 1, root_now);
      if (i >= pal[i])
        root_now = upd(i-pal[i], -1, root_now);
    }
    root[i] = root_now;
  }
  build_sa();
  build_lcp();
  for (int i = 0; i < n; i++) {
    sparse[0][i] = i;
  }
  for (int i = 0; i < LN; i++) {
    for (int j = 0; j + (1<<(i+1)) <= n; j++) {
      int a = sparse[i][j], b = sparse[i][j+(1<<i)];
      sparse[i+1][j] = lcp[a] < lcp[b] ? a : b;
    }
  }
  cnt[0] = n - sa[0];
  for (int i = 1; i < n; i++) {
    cnt[i] = cnt[i-1] + n - sa[i] - lcp[i-1];
  }
  sumpal[n-1] = 0;
  for (int i = n-2; i >= 0; i--) {
    int l, r;
    l = i+1; r = n-1;
    while (l < r) {
      int mid = (l+r) >> 1;
      if (lcp[get_rmq(i, mid)] >= lcp[i])
        l = mid + 1;
      else
        r = mid;
    }
    int cntpal = get(sa[i] + sa[i] + 1, root[sa[i] + sa[i] + lcp[i]]);
    sumpal[i] = sumpal[l] + 1LL * (l-i) * cntpal;
  }
  for (int i = 0; i < n; i++) {
    sumpal2[i] = get(sa[i] + sa[i] + 1, root[m-1]) + (i ? sumpal2[i-1] : 0);
  }
  for (int i = 0; i < q; i++) {
    long long k;
    scanf("%lld", &k);
    if (k > sumpal2[n-1]) {
      puts("-1");
      continue;
    }
    long long lo = 0, hi = cnt[n-1];
    while (lo < hi) {
      long long mid = (lo+hi+1)>>1;
      int id = lower_bound(cnt, cnt+n, mid) - cnt;
      long long now = mid;
      if (id) {
        now -= cnt[id-1];
        now += lcp[id-1];
      }
      long long palnow = id ? sumpal2[id-1] : 0;

      int l, r;
      l = id; r = n-1;
      while (l < r) {
        int mm = (l+r) >> 1;
        if (lcp[get_rmq(id, mm)] >= now)
          l = mm + 1;
        else
          r = mm;
      }
      int cntpal = get(sa[id] + sa[id] + 1, root[sa[id] + sa[id] + now]);
      palnow += sumpal[l] + 1LL * (l - id+1) * cntpal;
      if (palnow >= k)
        hi = mid - 1;
      else
        lo = mid;
    }
    lo++;
    int id = lower_bound(cnt, cnt+n, lo) - cnt;
    if (id) {
      lo -= cnt[id-1];
      lo += lcp[id-1];
    }   
    printf("%lld\n", calc(sa[id], sa[id] + lo));
  }
  return 0;
}