#include <bits/stdc++.h>

using namespace std;

const int N = 20 * 20 * 20;

signed char mem[N][20][20][22];
int n, k;
vector<pair<int, int>> points;

bool solve(int id, int a, int b, int c) {
  if (c == k && a == 0 && b == 0)
    return true;
  if (c >= k || id >= n)
    return false;
  if (mem[id][a][b][c] != -1)
    return mem[id][a][b][c];
  mem[id][a][b][c] = 0;
  bool ret = solve(id+1, (a + points[id].first) % k, (b + points[id].second) % k, c+1);
  if (ret)
    return mem[id][a][b][c] = 1;
  return mem[id][a][b][c] = solve(id+1, a, b, c);
}

void backtrack(int id, int a, int b, int c) {
  if (c == k && a == 0 && b == 0)
    return;
  if (c >= k || id >= n)
    return;
  if (solve(id+1, (a + points[id].first) % k, (b + points[id].second) % k, c+1)) {
    printf("%d%c", id+1, c+1 == k ? '\n' : ' ');
    backtrack(id+1, (a + points[id].first) % k, (b + points[id].second) % k, c+1);
  }
  else
    backtrack(id+1, a, b, c);
}

int main() {
  scanf("%d %d", &n, &k);
  points.resize(n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    points[i] = make_pair(x, y);
  }
  if (n > 1LL * k * k * (k-1)) {
    vector<vector<int>> cnt(k, vector<int>(k, 0));
    for (pair<int, int> p : points) {
      ++cnt[p.first % k][p.second % k];
    }
    int a = 0, b = 0;
    for (int i = 0; i < k; ++i) {
      for (int j = 0; j < k; ++j) {
        if (cnt[i][j] > cnt[a][b]) {
          a = i;
          b = j;
        }
      }
    }
    int tot = k;
    for (int i = 0; i < n; ++i) {
      pair<int, int> p = points[i];
      if ((p.first % k) == a && (p.second % k) == b) {
        --tot;
        printf("%d%c", i+1, tot == 0 ? '\n' : ' ');
      }
    }
    return 0;
  }
  memset(mem, -1, sizeof mem);
  if (!solve(0, 0, 0, 0))
    puts("-1");
  else
    backtrack(0, 0, 0, 0);

  return 0;
}
