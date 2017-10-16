#include <bits/stdc++.h>

using namespace std;

const int N = 3030;
int n, m;
char s[N][N], tmp[N][N];
int r[N*2], b[N*2];
bool used[N * 2];

int solve() {
  memset(used, 0, sizeof used);
  memset(r, 0, sizeof r);
  memset(b, 0, sizeof b);
  int nr = 0, nb = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] == 'R')
        r[i]++, r[n+j]++, nr++;
      else
        b[i]++, b[n+j]++, nb++;
    }
  }
  set<int> st;
  set<int> sr, sb;
  for (int i = 0; i < n + m; i++) {
    if (b[i] == 0 || r[i] == 0)
      st.insert(i);
    if (i < n) continue;
    if (b[i] == 0)
      sr.insert(i);
    if (r[i] == 0)
      sb.insert(i);
  }
  int p = 0, q = 0;
  while (!st.empty() && p < n && q < m) {
    auto it = st.begin();
    int v = *it;
    if (v >= n) {
      if (sr.size() < sb.size()) {
        while (!sr.empty()) {
          it = sr.begin();
          int u = *it;
          sr.erase(it);
          if (!used[u]) {
            v = u;
            break;
          }
        }
      }
      else {
        while (!sb.empty()) {
          it = sb.begin();
          int u = *it;
          sb.erase(it);
          if (!used[u]) {
            v = u;
            break;
          }
        }
      }
    }
    used[v] = 1;
    st.erase(v);
    sr.erase(v);
    sb.erase(v);
    if (v < n) {
      p++;
      for (int i = 0; i < m; i++) {
        if (used[i+n]) continue;
        if (s[v][i] == 'R')
          r[i+n]--,nr--;
        else
          b[i+n]--, nb--;
        if (r[i+n] == 0 || b[i+n] == 0)
          st.insert(i+n);
        if (r[i+n] == 0)
          sb.insert(i+n);
        if (b[i+n] == 0)
          sr.insert(i+n);
      }
    }
    else {
      q++;
      v -= n;
      for (int i = 0; i < n; i++) {
        if (used[i]) continue;
        if (s[i][v] == 'R')
          r[i]--,nr--;
        else
          b[i]--,nb--;
        if (r[i] == 0 || b[i] == 0)
          st.insert(i);
      }
    }
  }
  if (p < n && q < m)
    return -1;
  return p + q;
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%s", s[i]);
  }
  int ans = solve();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      tmp[j][i] = s[i][j];
  }
  swap(n, m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      s[i][j] = tmp[i][j];
  }
  if (ans == -1)
    ans = solve();
  else {
    int ret = solve();
    if (ret != -1)
      ans = min(ans, ret);
  }
  printf("%d\n", ans);
  return 0;
}