#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define MAXN 500

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
        while (!pq.empty()) {
            pair<int, int> top = pq.top();
            pq.pop();
            int v = top.second, c = -top.first;
            if (vis[v]) continue;
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

int main()
{
    int n, m, s, t;
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for (int i = 0; i < m; ++i) {
        int u, v, c, w;
        scanf("%d%d%d%d", &u, &v, &c, &w);
        Edge a(v,c,w,edge[v].size()), b(u,0,-w,edge[u].size());
        edge[u].push_back(a);
        edge[v].push_back(b);
    }
    pair<int, int> ret = mcmf(n, s, t);
    printf("%d %d\n", ret.first, ret.second);
    return 0;
}
