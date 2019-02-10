#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, M = 6;

vector<int> pos[1 << M][1 << M];

char s[N][M + 2];

int n, m;
int pmask;

bool cmp(int l, int r) {
  for (int i = 0; i < m; ++i) {
    if ((pmask & (1 << i)) == 0) continue;
    if (s[l][i] != s[r][i])
      return s[l][i] < s[r][i];
  }
  return false;
}

bool eq(int l, int r) {
  for (int i = 0; i < m; ++i) {
    if ((pmask & (1 << i)) == 0) continue;
    if (s[l][i] != s[r][i])
      return false;
  }
  return true;
}


int main() {
  scanf("%d %d", &n, &m);
  int nmask = 1 << m;
  for (int i = 0; i < n; ++i) {
    scanf("%s", s[i]);
    int mask = 0;
    for (int j = 0; j < m; ++j)
      if (s[i][j] != '?')
        mask |= 1 << j;
    for (int j = 0; j < nmask; ++j) {
      if ((j & mask) == j) {
        pos[mask][j].push_back(i);
      }
    }
  }
  for (int i = 0; i < nmask; ++i) {
    for (int j = 0; j < nmask; ++j) {
      if ((i & j) != j) continue;
      pmask = j;
      sort(pos[i][j].begin(), pos[i][j].end(), cmp);
    }
  }
  long long ans = 0;
  for (int i = 0; i < nmask; ++i) {
    pmask = i;
    for (int p = 0; p < pos[i][i].size();) {
      int q = p;
      while (q < pos[i][i].size() && eq(pos[i][i][p], pos[i][i][q])) ++q;
      ans += 1LL * (q - p) * (q - p - 1) / 2;
      p = q;
    }
    for (int j = i+1; j < nmask; ++j) {
      int b = i&j;
      pmask = b;
      for (int p = 0, x = 0; p < pos[i][b].size();) {
        int q = p;
        while (q < pos[i][b].size() && eq(pos[i][b][p], pos[i][b][q])) ++q;
        while (x < pos[j][b].size() && cmp(pos[j][b][x], pos[i][b][p])) ++x;
        int y = x;
        while (y < pos[j][b].size() && eq(pos[i][b][p], pos[j][b][y])) ++y;
        ans += 1LL * (y - x) * (q - p);
        p = q;
        x = y;
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}