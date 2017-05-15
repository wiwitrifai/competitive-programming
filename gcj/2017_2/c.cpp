#include <bits/stdc++.h>

using namespace std;

const int N = 55;

char s[N][N];
pair< int, int > id[N * N];
int r, c, n;
int laser[N][N];
vector< int > fr[N][N];
vector< int > g[N * N];
int val[N * N], din[N * N];
bool live[N * N];
bool dfs1(int v) {
  live[v] = 1;
  for (int u : g[v]) if (!live[u])
    dfs1(u);
}
int low[N * N], num[N * N], vis[N * N], com[N * N], ncom, cntr;
vector< int > S;
void tarjanSCC(int v) {
  if (live[v]) return;
  low[v] = num[v] = ++cntr;
  vis[v] = 1;
  S.push_back(v);
  for(auto u : g[v]) {
    if(num[u] == -1)
      tarjanSCC(u);
    if(vis[u])
      low[v] = min(low[v], low[u]);
  }
  if(low[v] == num[v]) {
    while(1) {
      int u = S.back(); S.pop_back(); vis[u] = 0;
      com[u] = ncom;
      if(u == v)
        break;
    }
    ncom++;
  }
}

// kiri, kanan, atas, bawah
int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
int vs[N][N][4];

int main() {
  time_t startt = clock();
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    n = 0;
    memset(laser, -1, sizeof laser);
    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; i++) {
      scanf("%s", s[i]);
      for (int j = 0; j < c; j++) {
        if (s[i][j] == '-' || s[i][j] == '|') {
          id[n] = {i, j};
          laser[i][j] = n++;
        }
        fr[i][j].clear();
      }
    }
    bool res = 1;
    for (int i = 0; i < n; i++) {
      int cnt = 0;
      for (int j = 0; j < 4; j += 2) {
        queue< pair< pair< int, int >, int > > que;
        que.push(make_pair(make_pair(id[i].first+dx[j], id[i].second+dy[j]), j));
        que.push(make_pair(make_pair(id[i].first+dx[j+1], id[i].second+dy[j+1]), j+1));
        vector< pair< int, int > > em;
        bool ok = 1;
        memset(vis, 0, sizeof vis);
        while (!que.empty()) {
          auto it = que.front(); que.pop();
          int x = it.first.first, y = it.first.second, dir = it.second;
          // cerr << x << " " << y << " " << dir << endl;
          if (x < 0 || x >= r || y < 0 || y >= c) continue;
          if (vs[x][y][dir]) continue;
          vs[x][y][dir] = 1;
          if (s[x][y] == '.') {
            em.emplace_back(x, y);
            x += dx[dir];
            y += dy[dir];
            que.push(make_pair(make_pair(x, y), dir));
          }
          else if (s[x][y] == '-' || s[x][y] == '|') {
            ok = 0;
            break;
          }
          else if (s[x][y] == '#')
            continue;
          else if (s[x][y] == '/') {
            dir = 3-dir;
            x += dx[dir];
            y += dy[dir];
            que.push(make_pair(make_pair(x, y), dir));
          }
          else {
            dir = (dir+2) % 4;
            x += dx[dir];
            y += dy[dir];
            que.push(make_pair(make_pair(x, y), dir));
          }
        }
        if (ok) {
          for (auto it : em) {
            fr[it.first][it.second].push_back(i + (j/2) * n);
          }
          cnt++;
        }
      }
      if (cnt == 0) {
        res = 0;
        break;
      }
    }
    if (res) {
      memset(val, -1, sizeof val);
      memset(live, 0, sizeof live);
      for (int i = 0; i < 2 * n; i++) g[i].clear();
      for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) if (s[i][j] == '.') {
          for (int v : fr[i][j])
            cerr << i << " " << j << " " << v << endl;
          if (fr[i][j].size() < 1) {
            res = 0;
            break;
          }
          else if (fr[i][j].size() == 1) {
            live[fr[i][j][0]] = 1;
          }
          else if (fr[i][j].size() >= 2) {
            int u = fr[i][j][0], v = fr[i][j][1];
            g[(u+n) % (2 * n)].push_back(v);
            g[(v+n) % (2 * n)].push_back(u);
          }
        }
      }
      for (int i = 0; i < 2 * n; i++) if (live[i]) {
        dfs1(i);
      }
      for (int i = 0; i < 2 * n; i++) if (live[i])
        if (live[(i + n) % (2 * n)]) {
          res = 0;
          break;
        }
      memset(vis, 0, sizeof 0);
      memset(num, -1, sizeof num);
      ncom = 0;
      cntr = 0;
      for (int i = 0; i < 2 * n; i++) if (num[i] == -1 && res) {
        S.clear();
        tarjanSCC(i);
      }
      for (int i = 0; i < n; i++) {
        if (com[i] == com[i+n]) {
          res = 0;
          break;
        }
      }
      memset(din, 0, sizeof din);
      for (int i = 0; i < 2 * n; i++) if (!live[i]) {
        for (int u : g[i]) if (!live[u])
          din[u]++;
      }
      stack< int > st;
      if (res)
      for (int i = 0; i < 2 * n; i++) if (!live[i]) {
        if (din[i] == 0)
          st.push(i);
      }
      while (!st.empty()) {
        int v = st.top(); st.pop();
        if (val[v % n] == -1) val[v % n] = (v + n) % (2 * n);
        for (int u : g[v]) if (!live[u]) {
          din[u]--;
          if (din[u] == 0)
            st.push(u);
        }
      }
    }
    printf("Case #%d: %s\n", tc, res ? "YES" : "NO");
    if (res) {
      for (int i = 0; i < n; i++) {
        if (val[i] < n)
          s[id[i].first][id[i].second] = '-';
        else
          s[id[i].first][id[i].second] = '|';
      }
      for (int i = 0; i < r; i++)
        printf("%s\n", s[i]);
    }
    cerr << "~ #" << tc << " done! time : " << (double)(clock()-startt) * 1000/CLOCKS_PER_SEC << " ms" << endl;
  }
  return 0;
}