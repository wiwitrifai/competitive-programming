#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 6, MAGIC = 350, SZ = (N + MAGIC - 1)/MAGIC + 5;
const long long inf = 1e18;

vector<pair<int, long long>> g[N];
long long d[SZ][SZ], val2[SZ][SZ], val[N];
int tom[7][N], to[SZ][SZ], pv[N][7];
long long dist[N], pre[N], dd[N][7];

void dijkstra(int s, int low, int hi) {
  for (int i = low; i <= hi; i++)
    dist[i] = inf, pre[i] = -1;
  dist[s] = 0;
  set<pair<long long,int>> st;
  st.insert(make_pair(0, s));
  while (!st.empty()) {
    auto it = st.begin();
    int v = it->second;
    st.erase(it);
    for (auto e : g[v]) {
      int u = e.first;
      if (u < low || u > hi)
        continue;
      if (dist[u] <= dist[v] + e.second) continue;
      st.erase(make_pair(dist[u], u));
      dist[u] = dist[v] + e.second;
      pre[u] = v;
      st.insert(make_pair(dist[u], u));
    }
  }
}

int main() {
  int n, m, q;
  scanf("%d %d %d", &m, &n, &q);
  for (int i = 0; i < m-1; i++) {
    for (int j = 0; j < n; j++) {
      int u = j * m + i, v = u + 1;
      long long w;
      scanf("%lld", &w);
      g[u].emplace_back(v, w);
      g[v].emplace_back(u, w);
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n-1; j++) {
      int u = j * m + i, v = u + m;
      long long w;
      scanf("%lld", &w);
      g[u].emplace_back(v, w);
      g[v].emplace_back(u, w);
    }
  }
  int p = (n + MAGIC - 1) / MAGIC, mp = m * p;
  for (int i = 0; i < mp; i++) {
    for (int j = 0; j < mp; j++) {
      to[i][j] = -1;
      d[i][j] = inf;
    }
    d[i][i] = 0;
  }
  memset(to, -1, sizeof to);
  memset(tom, -1, sizeof tom);
  memset(pv, -1, sizeof pv);
  memset(val, 0, sizeof val);
  memset(val2, 0, sizeof val2);
  for (int i = 0; i < n; i += MAGIC) {
    for (int j = 0; j < m; j++) {
      int now = i * m + j;
      int u = i/MAGIC * m + j;
      int low = i * m, hi = (i + MAGIC + 1) * m - 1;
      low = max(0, low);
      hi = min(hi, n * m - 1);
      dijkstra(now, low, hi);
      for (int k = low; k <= hi; k++) {
        tom[j][k] = pre[k], dd[k][j] = dist[k], pv[k][j] = u;
        // cerr << k << " " << j << " " << u << endl;
      }

      for (int k = 0; k < m; k++) {
        long long val = dist[i * m + k];
        int v = (i/MAGIC) * m + k;
        if (d[u][v] > val) {
          d[u][v] = d[v][u] = val;
          to[u][v] = u;
          to[v][u] = v;
          // cerr << u << " -> " << v << " " << val << endl;
        }
      }
      if (i + MAGIC < n) {
        for (int k = 0; k < m; k++) {
          long long val = dist[(i + MAGIC) * m + k];
          int v = (i/MAGIC + 1) * m + k;
          if (d[u][v] > val) {
            d[u][v] = d[v][u] = val;
            // cerr << u << " -> " << v << " " << val << endl;
            to[u][v] = u;
            to[v][u] = v;
          }
        }
      }
    }
    for (int j = 0; j < m; j++) {
      int now = i * m + j;
      int u = i/MAGIC * m + j;
      int low = (i - MAGIC + 1) * m, hi = (i + 1) * m - 1;
      low = max(0, low);
      hi = min(hi, n * m - 1);
      dijkstra(now, low, hi);
      for (int k = low; k <= hi; k++) {
        tom[m + j][k] = pre[k], dd[k][m + j] = dist[k], pv[k][m + j] = u;
        // cerr << k << " " << m+j << " " << u << endl;
      }
    }
  }
  for (int k = 0; k < mp; k++) {
    for (int i = 0; i < mp; i++) {
      for (int j = 0; j < mp; j++) {
        if (d[i][j] > d[i][k] + d[k][j]) {
          d[i][j] = d[i][k] + d[k][j];
          to[i][j] = to[k][j];
        }
      }
    }
  }
  while (q--) {
    int t, a, b, c, de;
    long long e;
    scanf("%d %d %d", &t, &a, &b);
    a--; b--;
    if (t == 1) {
      scanf("%d %d %lld", &c, &de, &e);
      c--; de--;
      int u = b * m + a, v = de * m + c;
      // cerr << u << " - " << v << endl;
      int iu = 0, iv = 0;
      long long now = inf;
      for (int i = 0; i < 2 * m; i++) {
        if (pv[u][i] == -1) continue;
        for (int j = 0; j < 2 * m; j++) {
          if (pv[v][j] == -1) continue;
          long long cur = dd[u][i] + d[pv[u][i]][pv[v][j]] + dd[v][j];
          if (now > cur) {
            now = cur;
            iu = i;
            iv = j;
          }
        }
      }
      if (b/MAGIC == de/MAGIC && (b % MAGIC) > 0 && (de % MAGIC) > 0) {
        int low = (b/MAGIC * MAGIC + 1) * m, hi = low + (MAGIC - 1) * m - 1;
        low = max(low, 0);
        hi = min(hi, n * m - 1);
        low = 0, hi = n * m - 1;
        dijkstra(u, low, hi);
        if (dist[v] <= now) {
          while (v >= 0) {
            // cerr << v << " add " << endl; 
            val[v] += e;
            v = pre[v];
          }
          continue;
        }
      }
      int cur = u;
      while (tom[iu][cur] >= 0) {
        // cerr << "le " << cur << " " << tom[iu][cur] << endl;
        val[cur] += e;
        cur = tom[iu][cur];
      }
      cur = v;
      while (tom[iv][cur] >= 0) {
        // cerr << "ri " << cur << " " << tom[iv][cur] << endl;
        val[cur] += e;
        cur = tom[iv][cur];
      }
      u = pv[u][iu], v = pv[v][iv];
      if (u == v)
        val2[u][v] += e;
      // cerr << u << " to " << v << endl;
      while (to[u][v] >= 0) {
        // cerr << " mid " << v << " " << to[u][v] << endl;
        // cerr << d[u][v] << endl;
        val2[v][to[u][v]] += e;
        val2[to[u][v]][v] += e;
        v = to[u][v];
        if (to[u][v] >= 0) {
          int w = v/m * MAGIC * m + (v % m);
          // cerr << " min " << w << " " << e << endl;
          val[w] -= e;
        }
      }
    }
    else {
      int u = b * m + a;
      long long ans = val[u];
      // cerr << " get " << u << " " << ans << endl;
      if ((b % MAGIC) == 0) {
        u = b/MAGIC * m + a;
        int le = max(0, (b/MAGIC-1) * m), ri = min((b/MAGIC+2) * m, mp);
        for (int i = le; i < ri; i++) {
          for (int j = i; j < ri; j++) {
            if (d[i][u] + d[u][j] != d[i][j]) continue;
          // cerr << i << " d " << j << " " << val2[i][j] << endl;
          // cerr << d[i][u] << " + " << d[u][j] << " = " << d[i][j] << endl;
            ans +=  val2[i][j];
          }
        }
      }
      else {
        for (int i = 0; i < 2 * m; i++) {
          for (int j = i; j < 2 * m; j++) {
            if (d[pv[u][i]][pv[u][j]] != dd[u][i] + dd[u][j]) continue;
            // cerr << i << " " << j << " " << pv[u][i] << " " << pv[u][j] << " " << val2[pv[u][i]][pv[u][j]] << endl;
            ans += val2[pv[u][i]][pv[u][j]];
          }
        }
      }
      printf("%lld\n", ans);
    }
  }
  return 0;
}