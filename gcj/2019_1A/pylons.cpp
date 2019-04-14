#include <bits/stdc++.h>

using namespace std;

const int N = 22;

int used[N][N];
int cnt[N][N];
pair<int, int> ans[N * N];
vector<pair<int, int>> candd[N * N];

bool cek(int x, int y, int a, int b) {
  if (x == a || y == b)
    return false;
  if (x-y == a-b || x+y == a+b)
    return false;
  return true;
}
int r, c;
vector<pair<int, int>> cand;
bool cmp(pair<int, int> l, pair<int, int> r) {
  return cnt[l.first][l.second] < cnt[r.first][r.second];
}
bool dfs(int x, int y, int id = 0) {
  used[x][y] = id;
  int pos = -1;
  for (int i = 0; i < cand.size(); ++i)
    if (cand[i] == make_pair(x, y)) {
      pos = i;
      break;
    }
  assert(pos != -1);
  swap(cand[pos], cand.back());
  cand.pop_back();
  for (auto it : cand) {
    if (cek(it.first, it.second, x, y)) {
      --cnt[it.first][it.second];
    }
  }
  ++id;
  if (id == r * c) return true;
  sort(cand.begin(), cand.end(), cmp);
  candd[id] = cand;
  for (auto it : candd[id]) {
    int i, j;
    tie(i, j) = it;
    assert (used[i][j] == -1);
    if (!cek(x, y, i, j)) continue;
    bool res = dfs(i, j, id);
    if (res)
      return true;
  }
  used[x][y] = -1;
  cand.emplace_back(x, y);
  return false;
}

void solve(int tc) {
  printf("Case #%d: ", tc);
  scanf("%d %d", &r, &c);
  memset(cnt, 0, sizeof cnt);
  for (int u = 0; u < r*c; ++u) {
    for (int v = u+1; v < r * c; ++v) {
      int x = u/c, y = u%c;
      int p = v/c, q = v%c;
      if (!cek(x, y, p, q)) continue;
      ++cnt[x][y];
      ++cnt[p][q];
    }
  }
  cand.clear();
  for (int i = 0; i < r; ++i)
    for (int j = 0; j < c; ++j)
      cand.emplace_back(i, j);
  sort(cand.begin(), cand.end(), cmp);
  memset(used, -1, sizeof used);
  auto ccand = cand;
  for (auto it : ccand) {
    int i, j;
    tie(i, j) = it;
    bool res = dfs(i, j);
    if (res) {
      puts("POSSIBLE");
      for (int x = 0; x < r; ++x) {
        for (int y = 0; y < c; ++y) {
          assert(used[x][y] != -1);
          ans[used[x][y]] = {x+1, y+1};
        }
      }
      for (int x = 0; x < r * c; ++x) {
        printf("%d %d\n", ans[x].first, ans[x].second);
      }
      return;
    }
  }
  puts("IMPOSSIBLE");
}

int main() {
  time_t startt = clock();
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    solve(tc);
    cerr << "~ #" << tc << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << " s" << endl;
  }
  return 0;
}
