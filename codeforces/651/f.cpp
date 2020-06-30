#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

set<int> g[N];

pair<int, int> ask(vector<int> st) {
  printf("? %d\n", (int)st.size());
  bool first = true;
  for (int x : st) {
    if (!first) {
      printf(" ");
    } else {
      first = false;
    }
    printf("%d", x);
  }
  printf("\n");
  fflush(stdout);
  int x, d;
  scanf("%d %d", &x, &d);
  if (x == -1)
    exit(0);
  return make_pair(x, d);
}

void answer(int u, int v) {
  printf("! %d %d\n", u, v);
  fflush(stdout);
  char buffer[20];
  scanf("%s", buffer);
  if (buffer[0] == 'I')
    exit(0);
}

const int LG = 12;
int par[LG][N], lv[N];

void dfs(int v, int p) {
  par[0][v] = p;
  lv[v] = p == v ? 0 : lv[p] + 1;
  for (int i = 0; i + 1 < LG; ++i) {
    par[i+1][v] = par[i][par[i][v]];
  }
  for (int u : g[v]) {
    if (u == p) continue;
    dfs(u, v);
  }
}

int lca(int u, int v) {
  if (lv[u] > lv[v])
    swap(u, v);
  int diff = lv[v] - lv[u];
  for (int i = 0; i < LG; ++i) {
    if (diff & (1 << i)) {
      v = par[i][v];
    }
  }
  if (u == v)
    return v;
  for (int i = LG-1; i >= 0; --i) {
    if (par[i][u] != par[i][v]) {
      u = par[i][u];
      v = par[i][v];
    }
  }
  return par[0][v];
}

int anc(int v, int jump) {
  for (int i = 0; i < LG; ++i) {
    if (jump & (1 << i)) {
      v = par[i][v];
    }
  }
  return jump;
}

int dist(int u, int v) {
  return lv[u] + lv[v] - 2 * lv[lca(u, v)];
}
vector<int> nodes[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i <= n; ++i)
      g[i].clear();
    for (int i = 0; i < n-1; ++i) {
      int u, v;
      scanf("%d %d", &u, &v);
      g[u].insert(v);
      g[v].insert(u);
    }
    vector<int> all(n);
    iota(all.begin(), all.end(), 1);
    pair<int, int> root = ask(all);
    dfs(root.first, root.first);

    for (int i = 0; i <= n; ++i)
      nodes[i].clear();
    int cnt = 0;
    vector<bool> leaf(n+1, false);
    while (true) {
      bool done = true;
      for (int i = 1; i <= n; ++i) {
        if (g[i].size() == 1) {
          done = false;
          nodes[cnt].push_back(i);
          leaf[i] = true;
        }
      }
      for (int i = 1; i <= n; ++i) {
        if (leaf[i]) {
          for (int x : g[i]) {
            g[x].erase(i);
          }
          g[i].clear();
        }
      }
      if (done) break;
      ++cnt;
    }
    int lo = -1, hi = cnt-1;
    auto process = [&](int low) {
      vector<int> nod;
      for (int i = low; i >= 0; --i) {
        for (int x : nodes[i])
          nod.push_back(x);
      }
      return ask(nod);
    };
    int a = -1, b = -1;
    while (lo < hi) {
      int mid = (lo + hi + 1) >> 1;
      auto res = process(mid);
      if (res.second == root.second) {
        a = res.first;
        hi = mid - 1;
      } else {
        lo = mid;
      }
    }
    vector<int> cand;
    for (int i = 1; i <= n; ++i) {
      if (dist(a, i) == root.second)
        cand.push_back(i);
    }
    if (cand.size() == 1)
      b = cand[0];
    else
      b = ask(cand).first;
    answer(a, b);
  }
  return 0;
}
