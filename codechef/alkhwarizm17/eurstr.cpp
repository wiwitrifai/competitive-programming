#include <bits/stdc++.h>

using namespace std;

// suffix array
const int N = 2e6 + 5;
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
    for(int j = sa[pos[i] + 1]; s[j + k] == s[i + k] && s[j + k] != '\0' && s[i+k] != '\0'; k++);
    lcp[pos[i]] = k;
    if(k) k--;
  }
}

int off[N], len[N];
int sparse[20][N];
long long sum[N], sump[N];
int get(int l, int r) {
  if (r < l) return N;
  int ln = r-l+1;
  int lg = 31-__builtin_clz(ln);
  return min(sparse[lg][l], sparse[lg][r-(1<<lg)+1]);
}
int to[N];

int main() {
  int ns;
  scanf("%d", &ns);
  n = 0;
  for (int i = 0; i < ns; i++) {
    scanf("%s", s+n);
    off[i] = n;
    len[i] = strlen(s+n);
    for (int j = 0; j < len[i]; j++)
      to[n+j] = len[i]-j;
    n += len[i];
    to[n] = 0;
    s[n] = '\0';
    n++;
  }
  build_sa();
  build_lcp();
  sum[0] = 0;
  for (int i = 0; i < n; i++)
    sum[i+1] = sum[i] + to[sa[i]];
  sump[0] = 0;
  for (int i = 0; i < n-1; i++)
    sump[i+1] = sump[i] + lcp[i];
  for (int i = 0; i < n-1; i++)
    sparse[0][i] = lcp[i];
  for (int i = 0; i + 1 < 20; i++) {
    for (int j = 0; j + (1<<(i+1)) < n; j++) {
      sparse[i+1][j] = min(sparse[i][j], sparse[i][j+(1<<i)]);
    }
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int p, d;
    scanf("%d %d", &p, &d);
    p--;
    int l, r;
    int lo, hi;
    int now = pos[off[p]];
    lo = now, hi = n-1;
    while (lo < hi) {
      int mid = (lo + hi) >> 1;
      if (get(now, mid) >= d)
        lo = mid+1;
      else
        hi = mid;
    }
    r = lo;
    lo = -1;
    hi = now-1;
    while (lo < hi) {
      int mid = (lo + hi + 1) >> 1;
      if (get(mid, now-1) >= d)
        hi = mid-1;
      else
        lo = mid;
    }
    l = lo;
    // for (int i = l+1; i <= r; i++)
    //   cerr << s+sa[i] << " " << to[i] << endl;
    // cerr << sump[r]-sump[l+1]+d-1 << " " << sum[r+1] - sum[l+1] << endl;
    long long ans = sum[r+1]-sum[l+1] - (sump[r]-sump[l+1]+d-1);
    ans = max(ans, 0LL);
    printf("%lld\n", ans);
  }
  return 0;
}