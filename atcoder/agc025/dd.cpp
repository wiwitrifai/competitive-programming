#include <bits/stdc++.h>

using namespace std;

const int N = 666;

bool can[N][N];

int pos = N;
int n, a, b;
int cnt[N][N];
queue<pair<int, int > > que[N];
void sett(int x, int y, int v) {
  cnt[x][y] = v;
  pos = min(pos, v);
  que[v].push(make_pair(x, y));
}
vector<pair<int, int> > g[N][N];

void rem(int x, int y) {
  if (!can[x][y]) return;
  can[x][y] = 0;
  for (auto it : g[x][y]) {
    int xx = it.first, yy = it.second;
    if (!can[xx][yy]) continue;
    sett(xx, yy, cnt[xx][yy]-1);
  }
}

int main() {
  srand(time(0));
  scanf("%d %d %d", &n, &a, &b);
  for (int i = -2 * n; i <= 2 * n; ++i) {
    for (int j = -2 * n; j <= 2 * n; ++j) {
      int now = i * i + j * j;
      if (now != a && now != b) continue;
      int ra = 0, rb = 2 * n-1, ca = 0, cb = rb;
      ra = max(ra, ra-i);
      rb = min(rb, rb-i);
      ca = max(ca, ca-j);
      cb = min(cb, cb-j);
      for (int x = ra; x <= rb; ++x) {
        for (int y = ca; y <= cb; ++y) {
          int u = x+i, v = y+j;
          ++cnt[x][y];
          g[x][y].emplace_back(u, v);
        }
      }
    }
  }
  long long all = 0;
  for (int i = 0; i < 2 * n; ++i)
    for (int j = 0; j < 2 * n; ++j) {
      all += cnt[i][j];
    }
  vector<pair<int, int> > cand;
  for (int i = 0; i < 2 * n; ++i) {
    for (int j = 0; j < 2 * n; ++j) {
      cand.emplace_back(i, j);
    }
  }
  random_shuffle(cand.begin(), cand.end());
  for (auto it : cand) {
    int i = it.first, j = it.second;
    sett(i, j, cnt[i][j]);
    can[i][j] = 1;
  }
  vector<pair<int, int> > ans;
  pos = 0;
  while (pos < N && (int)ans.size() < n * n) {
    if (que[pos].empty()) {
      ++pos;
      continue;
    }
    int x = que[pos].front().first, y = que[pos].front().second;
    que[pos].pop();
    if (!can[x][y]) continue;
    ans.emplace_back(x, y);
    can[x][y] = 0;
    for (auto it : g[x][y]) {
      int xx = it.first, yy = it.second;
      rem(xx, yy);
    }
  }
  // assert(ans.size() == n * n);
  for (auto it : ans) {
    printf("%d %d\n", it.first, it.second);
  }
  cerr << all << " " << ans.size() << " " << n * n << endl;
  return 0;
}