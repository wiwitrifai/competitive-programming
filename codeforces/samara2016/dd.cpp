#include <bits/stdc++.h>

using namespace std;


#define INF 1000000000
#define MAXN 5050


struct Edge
{
    int t, c, w, r;
    Edge(int _t, int _c, int _w, int _r): t(_t), c(_c), w(_w), r(_r) {};
};


int pot[MAXN+5], prv[MAXN+5], dist[MAXN+5], vis[MAXN+5];
vector<Edge> edge[MAXN+5];


pair<int, int> mcmf(int n, int s, int t)
{
    fill(pot, pot+n, 0);
    int mf = 0, mc = 0;
    while (true) {
        priority_queue<pair<int, int> > pq;
        fill(dist, dist+n, INF);
        fill(vis, vis+n, 0);
        pq.push(make_pair(0, s));
        dist[s] = 0;
        // cerr << "dijkstra" << endl;
        while (!pq.empty()) {
            pair<int, int> top = pq.top();
            pq.pop();
            int v = top.second, c = -top.first;
            if (vis[v]) continue;
            // cerr << v << " " << c << endl;
            vis[v] = 1;
            for (int i = 0; i < edge[v].size(); ++i) {
                Edge &e = edge[v][i];
                int u = e.t;
                if (e.c == 0) continue;
                int ndist = dist[v] + e.w + pot[v]-pot[u];
                if (ndist < dist[u]) {
                    dist[u] = ndist;
                    prv[u] = e.r;
                    pq.push(make_pair(-ndist, u));
                }
            }
        }
        int v = t;
        // cerr << dist[t] << endl;
        if (dist[t] == INF) break;
        int flow = INF;
        for (int i = 0; i < n; ++i) pot[i] += dist[i];
        while (v != s) {
            Edge &r = edge[v][prv[v]], &e = edge[r.t][r.r];
            flow = min(flow, e.c);
            v = r.t;
        }
        mf += flow;
        v = t;
        while (v != s) {
            Edge &r = edge[v][prv[v]], &e = edge[r.t][r.r];
            e.c -= flow;
            r.c += flow;
            mc += e.w * flow;
            v = r.t;
        }
    }
    return make_pair(mf, mc);
}

const int N = 55;
int aa[N][N], dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

int n, m, t, s;
int b[N][N];

int id(int x, int y) {
  if (x < 0 || x >= n || y < 0 || y >= m)
    return t;
  return (x * m + y) * 2; 
}
char ans[N][N];

void dfs(int v) {
  if (vis[v])
    return;
  vis[v] = 1;
  for (auto e : edge[v]) if (e.c) {
    dfs(e.t);
  }
}
int main() {
  int r, c;
  scanf("%d %d %d %d", &n, &m, &r, &c);
  r--; c--;
  t = n * m * 2;
  int s = id(r, c) + 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", aa[i]+j);
      int u = id(i, j), v = id(i, j) + 1;
      Edge a(v, aa[i][j], 1, edge[v].size()), b(u, 0, 1, edge[u].size());
      edge[u].push_back(a);
      edge[v].push_back(b);
      swap(u, v);
      for (int k = 0; k < 4; k++) {
        int x = i + dx[k], y = j + dy[k];
        v = id(x, y);
        Edge a(v, INF, 0, edge[v].size()), b(u, 0, 0, edge[u].size());
        edge[u].push_back(a);
        edge[v].push_back(b);
      }
    }
  }
  pair< int, int > res = mcmf(n * m * 2 + 1, s, t);
  // cerr << res.first << " " << res.second << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int u = id(i, j);
      for (auto e : edge[u]) if (e.t == u+1) {
        b[i][j] = (e.c == 0);
        break;
      }
      // cerr << b[i][j] << " ";
    }
    // cerr << endl;
  }
  s /= 2;
  memset(vis, 0, sizeof vis);
  dfs(id(r, c)+1);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      ans[i][j] = vis[id(i, j)] && !vis[id(i, j)+1] ? 'X' : '.';
    }
    ans[i][m] = '\0';
  }
  // b[r][c] = 0;
  printf("%d\n", res.first);
  for (int i = 0; i < n; i++)
    printf("%s\n", ans[i]);
  return 0;
}