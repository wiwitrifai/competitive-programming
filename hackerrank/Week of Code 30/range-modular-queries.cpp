#include <bits/stdc++.h>

using namespace std;

const int N = 4e4 + 5, M = 202;
vector< pair< int, pair< int, int > > > add[N], sub[N];
int a[N], cnt[N], mod[M][N], ans[N];

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
  }
  for (int i = 0; i < q; i++) {
    int l, r, x, y;
    scanf("%d %d %d %d", &l, &r, &x, &y);
    l--;
    if (l >= 0)
      sub[l].push_back({i, {x, y}});
    add[r].push_back({i, {x, y}});
    ans[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    cnt[a[i]]++;
    for (int j = 1; j < M; j++)
      mod[j][a[i] % j]++;
    for (auto it : add[i]) {
      int id = it.first, x = it.second.first, y = it.second.second;
      if (x < M)
        ans[id] += mod[x][y];
      else
        for (int r = y; r < N; r += x)
          ans[id] += cnt[r];
    }
    for (auto it : sub[i]) {
      int id = it.first, x = it.second.first, y = it.second.second;
      if (x < M)
        ans[id] -= mod[x][y];
      else
        for (int r = y; r < N; r += x)
          ans[id] -= cnt[r];
    }
  }
  for (int i = 0; i < q; i++)
    printf("%d\n", ans[i]);
  return 0;
}