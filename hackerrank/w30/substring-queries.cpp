#include <bits/stdc++.h>

using namespace std;

// suffix array
const int N = 2e5 + 6;
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
    for(int j = sa[pos[i] + 1]; s[j + k] == s[i + k] && s[i+k] != '#'; k++);
    lcp[pos[i]] = k;
    if(k) k--;
  }
}

string str[N];
int off[N], to[N];

const int LG = 19, LEN = 128, MAGIC = (2e5 + 5)/LEN;
int sp[LG][N], par[LG][N];
set< int > idx[N];
int dp[MAGIC+5][MAGIC+5], last[MAGIC+5], tom[N];

int get(int l, int r) {
  int len = r-l + 1;
  if (len <= 0) return 0;
  int lg = 31 - __builtin_clz(len);
  return min(sp[lg][l], sp[lg][r-(1<<lg)+1]);
}

int main() {
  int m, q;
  scanf("%d %d", &m, &q);
  int cur = 0;
  for (int i = 0; i < m; i++) {
    cin >> str[i];
    off[i] = cur;
    for (int j = 0; j < str[i].size(); j++, cur++)
      s[cur] = str[i][j], to[cur] = i;
    to[cur] = -1;
    s[cur++] = '#';
  }
  n = cur;
  build_sa();
  build_lcp();
  for (int i = 0; i < n; i++) {
    if (to[sa[i]] == -1) continue;
    idx[to[sa[i]]].insert(i);
  }
  for (int i = 0; i < n; i++) {
    sp[0][i] = lcp[i];
  }
  for (int i = 0; i + 1 < LG; i++) {
    for (int j = 0; j + (1<<(i+1)) <= n; j++) {
      sp[i+1][j] = min(sp[i][j], sp[i][j + (1<<i)]);
    }
  }
  memset(tom, -1, sizeof tom);
  memset(last, -1, sizeof last);
  int ntom = 0;
  for (int i = 0; i < m; i++) {
    if (str[i].size() <= LEN) continue;
    tom[i] = ntom++;
  }
  for (int i = 0; i < n; i++) {
    int now = to[sa[i]];
    if (now == -1 || tom[now] == -1) continue;
    now = tom[now];
    last[now] = i;
    for (int j = 0; j < ntom; j++) {
      if (j == now) continue;
      if (last[j] == -1) continue;
      dp[j][now] = dp[now][j] = max(dp[now][j], get(last[j], i-1));
    }
  }
  while (q--) {
    int u, v;
    scanf("%d %d", &u, &v);
    if (u == v) {
      printf("%d\n", str[u].size());
      continue;
    }
    if (str[u].size() > str[v].size())
      swap(u, v);
    if (tom[u] != -1) {
      printf("%d\n", dp[tom[u]][tom[v]]);
      continue;
    }
    int ans = 0;
    for (int i = 0; i < str[u].size(); i++) {
      int now = pos[off[u] + i];
      auto it = idx[v].lower_bound(now);
      if (it != idx[v].end()) {
        ans = max(ans, get(now, (*it) - 1));
      }
      if (it != idx[v].begin()) {
        it--;
        ans = max(ans, get(*it, now - 1));
      }
    }
    ans = min(ans, (int)min(str[u].size(), str[v].size()));
    printf("%d\n", ans);
  }
  return 0;
}