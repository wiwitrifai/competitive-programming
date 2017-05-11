#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector< pair< int, int > > fo[2];
int c[2], n, ma[N];
int get(vector< pair< int, int > > & f, int b) {
  int ret = 0;
  ma[0] = 0;
  for (int i = 0; i < f.size(); i++)
    ma[i+1] = max(ma[i], f[i].second);
  for (int i = (int)f.size() - 1, j = 0; i >= 0; i--) {
    while (j < i && f[i].first + f[j].first <= b) j++;
    if (min(i, j) > 0)
      ret = max(ret, ma[min(i, j)] + f[i].second);
  }
  return ret;
}

int main() {
  scanf("%d %d %d", &n, c, c+1);
  for (int i = 0; i < n; i++) {
    int b, p;
    char s[6];
    scanf("%d %d %s", &b, &p, s);
    if (s[0] == 'C')
      fo[0].emplace_back(p, b);
    else
      fo[1].emplace_back(p, b);
  }
  int ans = 0, best[2];
  best[0] = best[1] = 0;
  for (int i = 0; i < 2; i++) {
    sort(fo[i].begin(), fo[i].end());
    for (int j = 0; j < fo[i].size(); j++) {
      if (fo[i][j].first <= c[i])
        best[i] = max(best[i], fo[i][j].second);
    }
  }
  if (best[0] > 0 && best[1] > 0)
    ans = max(ans, best[0] + best[1]);
  ans = max(ans, max(get(fo[0], c[0]), get(fo[1], c[1])));
  printf("%d\n", ans); 
  return 0;
}