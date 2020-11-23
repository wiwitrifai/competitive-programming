#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7, N = 505;

int a[N][N];

int main() {
  int n;
  scanf("%d", &n);
  vector<int> all;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%d", &a[i][j]);
      if (i != j)
        all.push_back(a[i][j]);
    }
  }
  sort(all.begin(), all.end());
  all.erase(unique(all.begin(), all.end()), all.end());
  int low = 0, hig = (int)all.size() - 1;
  vector<int> col(n, -1);
  while (low < hig) {
    int mid = (low + hig + 1) >> 1;
    int val = all[mid];
    bool ok = true;
    fill(col.begin(), col.end(), -1);
    for (int i = 0; i < n && ok; ++i) {
      if (col[i] != -1) continue;
      queue<int> que;
      col[i] = 0;
      que.push(i);
      while (!que.empty() && ok) {
        int v = que.front();
        que.pop();
        for (int u = 0; u < n; ++u) {
          if (u == v) continue;
          if (a[v][u] >= val) continue;
          if (col[u] != -1) {
            ok &= col[u] != col[v];
          } else {
            col[u] = !col[v];
            que.push(u);
          }
        }
      }
    }
    if (ok) {
      low = mid;
    } else {
      hig = mid - 1;
    }
  }
  int ans = all[low];
  printf("%d\n", ans);
  return 0;
}
