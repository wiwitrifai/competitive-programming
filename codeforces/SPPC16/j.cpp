#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

int a[N], d[N];
vector<pair<int, int>> ways[N];   // 2 dan 3
bool vis[N];

// return 1 if ambiguous, 0 is not
bool dfs(int now) {
  if (now == 0) return 0;
  if (vis[now]) return 0;
  vis[now] = 1;
  //printf("%d\n", now);
  if (now >= 2 && a[now - 1] == 0) {
    if (dfs(now - 2)) return 1;
    for (auto it : ways[now - 2]) ways[now].emplace_back(it.first + 1, it.second);
  }
  if (now >= 3 && a[now - 2] == 0) {
    if (dfs(now - 3)) return 1;
    for (auto it : ways[now - 3]) ways[now].emplace_back(it.first, it.second + 1);
  }
  sort(ways[now].begin(), ways[now].end());
  ways[now].resize(distance(ways[now].begin(), unique(ways[now].begin(), ways[now].end())));
  return ways[now].size() > 1;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", d + i);
  ways[0].emplace_back(0, 0);
  int dua = 0, tiga = 0;
  bool ambiguous = false;
  for (int i = 1; i <= n; i++) {
    int j = i;
    while (j + 1 <= n && d[j + 1] - d[j] < 2000) j++;
    //printf("%d %d\n", i, j);
    int len = j - i + 1;
    a[1] = 0;
    for (int k = i + 1; k <= j; k++) {
      a[k - i + 1] = (d[k] - d[k - 1] <= 1000);
    }
    if (dfs(len)) {
      ambiguous = 1;
    } else if (ways[len].empty()) {
      puts("Impossible");
      /*
      if (n == 299999) {
        printf("%d\n", len);
        for (int k = i; k <= j; k++) printf("%d ", d[k] - d[k - 1]);
      }
      */
      return 0;
    } else {
      dua += ways[len][0].first;
      tiga += ways[len][0].second;
      for (int k = 1; k <= len; k++) {
        ways[k].clear();
        vis[k] = 0;
      }
    }
    i = j;
  }
  if (ambiguous) {
    puts("Ambiguous");
    return 0;
  }
  printf("Cars without trailers: %d\n", dua);
  printf("Cars with trailers: %d\n", tiga);

  return 0;
}