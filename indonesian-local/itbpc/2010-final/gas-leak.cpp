#include <bits/stdc++.h>

using namespace std;
#define INF 111111

// things that handle max flow
struct edge {
    int j, flow, cap;
    edge *pair;
    edge(int j, int cap): j(j), flow(0), cap(cap), pair(NULL) {}
};

struct flow {
    int n;
    vector<edge*> *adj;
    edge **parent;
    int *flowto;
    int ans;
    flow(int n): n(n), ans(0) {
        adj = new vector<edge*>[n];
        for (int i = 0; i < n; i++) {
            adj[i].clear();
        }
        parent = new edge*[n];
        flowto = new int[n];
    }   
    void add_edge(int i, int j, int front, int back = 0) {
        // back is the capacity of the backward direction.
        // if back = 0, then edge is directed.
        edge *ef = new edge(j, front);
        edge *eb = new edge(i, back);
        ef->pair = eb;
        eb->pair = ef;
        adj[i].push_back(ef);
        adj[j].push_back(eb);
    }

    int aug(int s, int t) {
        // BFS-augment from s to t
        vector<int> queue;
        for (int i = 0; i < n; i++) flowto[i] = 0;
        queue.push_back(s);
        flowto[s] = INF;
        for (int f = 0; f < queue.size(); f++) {
            int i = queue[f];
            for (int nb = 0; nb < adj[i].size(); nb++) {
                edge *e = adj[i][nb];
                int j = e->j;
                if (!flowto[j]) {
                    int delta = e->cap - e->flow;
                    if (delta > 0) {
                        flowto[j] = min(flowto[i], delta);
                        parent[j] = e;
                        if (j == t) return flowto[j];
                        queue.push_back(j);
                    }
                }
            }
        }
        return 0;
    }

    int max_flow(int s, int t) {
        // edmonds karp
        for (int flow = 0;;) {
            int res = aug(s, t);
            if (!res) return flow;
            flow += res;
            for (int j = t; j != s; j = parent[j]->pair->j) {
                parent[j]->flow += res;
                parent[j]->pair->flow -= res;
            }
        }
    }
};

char str[55][55];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  flow mf(n * m * 2 + 2);
  int s = n * m * 2, t = s+1;
  for (int i = 0; i < n; i++) {
    scanf("%s", str[i]);
    for (int j = 0; j < m; j++) {
      if (str[i][j] == 'X') continue;
      int u = i * m + j;
      if (i && str[i-1][j] != 'X') {
        int v = u - m;
        mf.add_edge(u * 2 + 1, v * 2, INF);
        mf.add_edge(v * 2 + 1, u * 2, INF);
      }
      if (j && str[i][j-1] != 'X') {
        int v = u - 1;
        mf.add_edge(u * 2 + 1, v * 2, INF);
        mf.add_edge(v * 2 + 1, u * 2, INF);
      }
      if (str[i][j] == 'P')
        mf.add_edge(u * 2, u * 2 + 1, 1);
      else
        mf.add_edge(u * 2, u * 2 + 1, INF);
      if (str[i][j] == 'R')
        mf.add_edge(s, u * 2, INF);
      if (str[i][j] == 'E')
        mf.add_edge(u * 2 + 1, t, INF);
    }
  }
  int ans = mf.max_flow(s, t);
  printf("%d\n", ans >= INF ? -1 : ans);
  return 0;
}