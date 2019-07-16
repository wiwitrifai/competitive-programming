#include <bits/stdc++.h>

using namespace std;

// suffix array
const int N = 2e5 + 5;
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

const int LG = 19;
int to[N], st[N];
int sp[LG][N];
long long ans[N];

int get(int l, int r) {
  int len = r - l + 1;
  int lg = 31 - __builtin_clz(len);
  return min(sp[lg][l], sp[lg][r - (1 <<lg) + 1]);
}

int main() {
#ifndef LOCAL
  freopen("standingout.in", "r", stdin);
  freopen("standingout.out", "w", stdout);
#endif
  int m;
  scanf("%d", &m);
  n = 0;
  for (int i = 0; i < m; ++i) {
    st[i] = n;
    scanf("%s", s+n);
    n += strlen(s+n);
    for (int j = st[i]; j < n; ++j)
      to[j] = i;
    to[n] = m;
    s[n++] = '#';
  }
  st[m] = n;
  st[m+1] = n+1;
  build_sa();
  build_lcp();
  for (int i = 0; i < n-1; ++i)
    sp[0][i] = lcp[i];
  for (int i = 0; i + 1 < LG; ++i) {
    for (int j = 0; j + (1 << (1 + i)) < n; ++j) {
      sp[i+1][j] = min(sp[i][j], sp[i][j + (1 << i)]);
    }
  }
  for (int i = 0, l = -1, r = 0, last = 0; i < n; ++i) {
    if (i == r) l = i-1;
    while (r < n && to[sa[r]] == to[sa[i]]) ++r;
    if (l >= 0)
      last = max(last, get(l, i-1));
    if (r < n)
      last = max(last, get(i, r-1));
    int now = sa[i];
    int til = st[to[now]+1] - now - 1;
    ans[to[now]] += max(til - last, 0);
    last = max(til, last);
    last = min(last, lcp[i]);
  }
  for (int i = 0; i < m; ++i)
    printf("%lld\n", ans[i]);
  return 0;
}