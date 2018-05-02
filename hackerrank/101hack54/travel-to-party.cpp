#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

const int N = 3e5 + 5, LG = 21, INF = 1e7;

int p[N], a[N], lv[N];
vector<int> vc[N], g[N];
bitset<1024> ada[N][5];
int anc[N];
int par[LG][N];

void dfs(int v, int d = 0) {
    lv[v] = d;
    for (int i = 0; i+1 < LG; ++i) {
        par[i+1][v] = par[i][par[i][v]];
    }
    for (int u : g[v]) {
        par[0][u] = v;
        dfs(u, d+1);
    }
}

int lca(int u, int v) {
    if (lv[v] < lv[u]) swap(u, v);
    int d = lv[v] - lv[u];
    for (int i = 0; i < LG; ++i)
        if (d & (1 << i))
            v = par[i][v];
    if (u == v) return v;
    for (int i = LG-1; i >= 0; --i)
        if (par[i][u] != par[i][v])
            u = par[i][u], v = par[i][v];
    return par[0][v];
}

int best[N], bef[N];
vector<pair<int, int> > que[N];
int m;

void dfs2(int v) {
    bef[v] = best[a[v]];
    best[a[v]] = lv[v];
    for (auto it : que[v]) {
        int i = it.first, j = it.second;
        int batas = lv[anc[i]];
        for (int k = 0; k < m; ++k) {
            if (best[k] >= batas)
                ada[i][j][k] = 1;
        }
    }
    for (int u : g[v]) {
        dfs2(u);
    }
    best[a[v]] = bef[v];
}
struct Edge {
  int from, to, cap, flow, index;
  Edge(int from, int to, int cap, int flow, int index) :
  from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct Dinic {
  int N;
  vector<vector<Edge> > G;
  vector<Edge *> dad;
  vector<int> Q;
 
  Dinic(int N) : N(N), G(N), dad(N), Q(N) {}
 
  void AddEdge(int from, int to, int cap) {
    G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
    if (from == to) G[from].back().index++;
    G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
  }

  long long BlockingFlow(int s, int t) {
    fill(dad.begin(), dad.end(), (Edge *) NULL);
    dad[s] = &G[0][0] - 1;
      
    int head = 0, tail = 0;
    Q[tail++] = s;
    while (head < tail) {
      int x = Q[head++];
      for (int i = 0; i < G[x].size(); i++) {
        Edge &e = G[x][i];
        if (!dad[e.to] && e.cap - e.flow > 0) {
          dad[e.to] = &G[x][i];
          Q[tail++] = e.to;
        }
      }
    }
    if (!dad[t]) return 0;

    long long totflow = 0;
    for (int i = 0; i < G[t].size(); i++) {
      Edge *start = &G[G[t][i].to][G[t][i].index];
      int amt = INF;
      for (Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
        if (!e) { amt = 0; break; }
        amt = min(amt, e->cap - e->flow);
      }
      if (amt == 0) continue;
      for (Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
        e->flow += amt;
        G[e->to][e->index].flow -= amt;
      }
      totflow += amt;
    }
    return totflow;
  }

  long long GetMaxFlow(int s, int t) {
    long long totflow = 0;
    while (long long flow = BlockingFlow(s, t))
      totflow += flow;
    return totflow;
  }
};

int cnt[33];

// Complete the maximumDishes function below.
void maximumDishes(int n, int m, int q) {
    // Take the rest of the input from standard input and print the answers to the queries in the standard output
    ::m = m;
    for (int i = 1; i < n; ++i) {
        scanf("%d", p+i), --p[i];
        g[p[i]].push_back(i);
    }
    for (int i = 0; i < n; ++i)
        scanf("%d", a+i), --a[i];
    dfs(0);
    for (int i = 0; i < q; ++i) {
        int c;
        scanf("%d", &c);
        vc[i].clear();
        while (c--) {
            int x;
            scanf("%d", &x);
            --x;
            vc[i].push_back(x);
        }
        anc[i] = vc[i][0];
        for (int j = 1; j < vc[i].size(); ++j)
            anc[i] = lca(anc[i], vc[i][j]);
        for (int j = 0; j < vc[i].size(); ++j)
            que[vc[i][j]].emplace_back(i, j);
    }
    memset(best, -1, sizeof best);
    dfs2(0);
    for (int i = 0; i < q; ++i) {
        int c = vc[i].size();
        for (int j = 0; j < (1 << c); ++j)
            cnt[j] = 0;
        for (int j = 0; j < m; ++j) {
            int mask = 0;
            for (int k = 0; k < c; ++k)
                if (ada[i][k][j])
                    mask |= 1 << k;
            ++cnt[mask];
        }
        Dinic mf((1 << c) + c + 2);
        int s = mf.N - 2, t = mf.N-1;
        for (int j = 0; j < (1 << c); ++j) {
            mf.AddEdge(s, j, cnt[j]);
            for (int k = 0; k < c; ++k)
                if (j & (1 << k))
                    mf.AddEdge(j, (1 << c) + k, INF);
        }
        for (int j = 0; j < c; ++j)
            mf.AddEdge((1 << c) + j, t, 0);
        int le = 0, ri = m/c;
        while (le < ri) {
            int mid = (le + ri + 1) >> 1;
            for (int i = 0; i < mf.N; ++i)
                for (Edge & e : mf.G[i]) {
                    e.flow = 0;
                }
            for (int i = 0; i < c; ++i) {
                int v = (1 << c) + i;
                for (Edge & e : mf.G[v]) {
                    if (e.to != t) continue;
                    e.cap = mid;
                }
            }
            int res = mf.GetMaxFlow(s, t);
            if (res == c * mid)
                le = mid;
            else
                ri = mid-1;
        }
        printf("%d\n", c * le);
    }
}

int main()
{
    string nmq_temp;
    getline(cin, nmq_temp);

    vector<string> nmq = split_string(nmq_temp);

    int n = stoi(nmq[0]);

    int m = stoi(nmq[1]);

    int q = stoi(nmq[2]);

    maximumDishes(n, m, q);

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
