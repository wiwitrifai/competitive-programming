#include <bits/stdc++.h>

using namespace std;

const int N = 2017;

char s[N][N];
int a[N][N], n, m;

int p[N * N];
int find(int x) {
  return p[x] < 0 ? x : p[x] = find(p[x]);
}

int merge(int x, int y) {
  if ((x = find(x)) == (y = find(y)))
    return -p[x];
  if (-p[x] < -p[y])
    swap(x, y);
  p[x] += p[y];
  p[y] = x;
  return -p[x];
}

int enc(int x, int y) {
  return x * m + y;
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++)
    scanf("%s", s[i]);
  for (int i = 0; i < n; i++)
    a[i][0] = i+1;

  vector<pair<int, pair<int, int > > > val;
  for (int j = 1; j < m; j++) {
    int same = -1, change = -1;
    for (int i = 0; i < n; i++) {
      if (s[i][j] == s[i][j-1])
        change = i;
      else
        same = i;
      a[i][j] = i - min(same, change);
      val.push_back({a[i][j], {i, j}});
    }
  }
  sort(val.begin(), val.end());
  int ans = max(n, m);
  int cur = ans;
  memset(p, -1, sizeof p);
  for (int i = val.size() - 1; i >= 0; i--) {
    ans = max(ans, val[i].first * merge(enc(val[i].second.first, val[i].second.second), enc(val[i].second.first, val[i].second.second-1))); 
  }
  printf("%d\n", ans);
  return 0;
}