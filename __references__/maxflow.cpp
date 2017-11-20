#define INF 1111111111

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

