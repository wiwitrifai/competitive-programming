#include <bits/stdc++.h>

using namespace std;

const int N = 201, M = 2e6 + 6;;
const long long inf = 3e18;

vector<pair<int, long long> > g[M];
int node[N][N];
vector<int> lef, rig;


void addEdge(int u, int v, long long w) {
  g[u].emplace_back(v, w);
}

int cd, md, cp, mp;

inline long long pangkalan(int x) {
  return 1LL * (x + mp - 1) / mp * cp;
}

inline long long startOnly(int x) {
  int d = min(x % mp, md);
  long long r = min(1LL * d * cd + pangkalan(x-d), pangkalan(x));
  int k = (min(md, x) - d) / mp;
  d += mp * k;
  r = min(r, 1LL * d * cd + pangkalan(x-d));
  d = min(x, md);
  r = min(r, 1LL * d * cd + pangkalan(x-d));
  return r;
}

inline long long bebas(int x) {
  long long r = min(1LL * x * cd, startOnly(x));
  int d = x % mp;
  r = min(r, 1LL * d * cd + pangkalan(x-d));
  return r;
}

inline long long pilih(int x, int q) {
  return q ? bebas(x) : pangkalan(x);
}
inline long long startPilih(int x, int q) {
  return q ? bebas(x) : startOnly(x);
}

long long dist[M];

int main() {
  scanf("%*s");
  int nodes = 0;
  int n, m;
  scanf("%d %d", &n, &m);
  scanf("%d %d %d %d", &cd, &md, &cp, &mp);
  int s, t;
  scanf("%d %d", &s, &t); --s, --t;
  int mm = max(mp, md)+1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < mm; ++j) {
      node[i][j] = nodes++;
      if (j > 0) {
        addEdge(node[i][j], node[i][j-1], 0);
        addEdge(node[i][0], node[i][j], startOnly(j));
      }
    }
  }
  lef.resize(mm-1);
  rig.resize(mm-1);
  while (m--) {
    int u, v, k, q;
    scanf("%d %d %d %d", &u, &v, &k, &q); --u, --v;
    q = !q;
    addEdge(node[u][0], node[v][0], startPilih(k, q));
    addEdge(node[v][0], node[u][0], startPilih(k, q));
    for (int i = k; i < mm; ++i) {
      addEdge(node[u][i], node[v][i-k], 0);
      addEdge(node[v][i], node[u][i-k], 0);
    }
    long long fullp = pilih(mp, q);
    if (k + 1 < 2 * mm) {
      for (int l = 1; l < k; ++l) {
        int now = nodes++;
        int r = k-l;
        if (l > mp)
          addEdge(now, now - mp,  fullp);
        else
          addEdge(now, node[u][mp-l], cp);
        if (l < mm)
          addEdge(node[u][l], now, 0);
        if (r > mp)
          addEdge(now, now + mp, fullp);
        else
          addEdge(now, node[v][mp-r], cp);
        if (r < mm)
          addEdge(node[v][r], now, 0);
        if (q) {
          if (l > 1)
            addEdge(now, now-1, cd);
          else {
            addEdge(node[u][0], now, startPilih(l, q));
            addEdge(now, node[u][0], pilih(l, q));
          }
          if (r > 1)
            addEdge(now, now+1, cd);
          else {
            addEdge(node[v][0], now, startPilih(r, q));
            addEdge(now, node[v][0], pilih(r, q));
          }
        }
      }
    }
    else {
      long long fullp = pilih(mp, q);
      for (int i = 0; i < mm-1; ++i) {
        int now = nodes++;
        lef[i] = now;
        int sisa = mp - i - 1;
        if (sisa >= 0)
          addEdge(now, node[u][sisa], cp);
        if (i+1 < mm)
          addEdge(node[u][i+1], now, 0);
        if (i >= mp) {
          addEdge(now, now-mp, cp);
          addEdge(now-mp, now, cp);
        }
        if (q) {
          if (i) {
            addEdge(now-1, now, cd);   
            addEdge(now, now-1, cd);
          }
          else {
            addEdge(node[u][0], now, cd);
            addEdge(now, node[u][0], cd);
          }
        }
      }
      for (int i = 0; i < mm-1; ++i) {
        int now = nodes++;
        rig[i] = now;
        int sisa = mp - i - 1;
        if (sisa >= 0)
          addEdge(now, node[v][sisa], cp);
        if (i+1 < mm)
          addEdge(node[v][i+1], now, 0);
        if (i >= mp) {
          addEdge(now, now-mp, cp);
          addEdge(now-mp, now, cp);
        }
        if (q) {
          if (i) {
            addEdge(now, now-1, cd);
            addEdge(now-1, now, cd);            
          }
          else {
            addEdge(node[v][0], now, cd);
            addEdge(now, node[v][0], cd);
          }
        }
      }
      int pasang = (k - 2) % mp, kali = (k - 2) / mp;
      for (int i = 0; i < lef.size(); ++i) {
        addEdge(lef[i], rig[pasang], fullp * kali);
        --pasang;
        if (pasang < 0)
          pasang += mp, --kali;
      }
      pasang = (k-2) % mp, kali = (k-2) / mp;
      for (int i = 0; i < rig.size(); ++i) {
        addEdge(rig[i], lef[pasang], fullp * kali);
        --pasang;
        if (pasang < 0)
          pasang += mp, --kali;
      }
    }
  }
  s = node[s][0], t = node[t][0];
  fill(dist, dist+nodes, inf);
  dist[s] = 0;
  priority_queue<pair<long long, int> > pq;
  pq.push(make_pair(-dist[s], s));
  while (!pq.empty()) {
    int v = pq.top().second;
    long long w = -pq.top().first;
    pq.pop();
    if (w != dist[v]) continue;
    for (auto it : g[v]) {
      long long nd = w + it.second;
      int u = it.first;
      if (dist[u] > nd) {
        dist[u] = nd;
        pq.push(make_pair(-nd, u));
      }
    }
  }
  printf("%lld\n", dist[t]);
  return 0;
}