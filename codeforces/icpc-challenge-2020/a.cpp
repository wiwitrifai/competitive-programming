#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void stats(vector<int> & a, string title) {
  cerr << " ====== stats: " << title << " ======= " << endl;
  int n = a.size();
  cerr << " size : " << a.size() << endl;
  int mini = a[0], maxi = a[0];
  long long sum = 0;
  for (int x : a) {
    mini = min(mini, x);
    maxi = max(maxi, x);
    sum += x;
  }
  cerr << " min : " << mini << endl;
  cerr << " max : " << maxi << endl;
  cerr << " avg : " << (double) sum / n << endl;
  cerr << " percentiles : ";
  vector<int> b(a);
  sort(b.begin(), b.end());
  for (int i = 0; i < n; i += n / 10) {
    cerr << b[i] << " ";
  }
  cerr << endl;
}


double score(vector<vector<int>>& graph, vector<vector<int>> & ans) {
  int n = graph.size();
  int m = 0;
  for (int i = 0; i < n; ++i)
    m += graph[i].size();
  m /= 2;
  vector<int> comp(n, -1);
  int k = ans.size();
  int cnt = 0;
  for (int i = 0; i < k; ++i) {
    for (int u : ans[i])
      comp[u] = i;
    cnt += ans[i].size();
  }
  assert(cnt == n);
  vector<int> ein(k, 0), sumdeg(k, 0);
  for (int i = 0; i < n; ++i) {
    for (int u : graph[i]) {
      if (comp[u] == comp[i])
        ++ein[comp[i]];
    }
    sumdeg[comp[i]] += graph[i].size();
  }
  double modularity = 0;
  for (int i = 0; i < k; ++i) {
    ein[i] /= 2;
    double x = (double)sumdeg[i] / (2.0 * m);
    modularity += (double)ein[i] / m - x * x;
  }
  double dense = 0;
  for (int i = 0; i < k; ++i) {
    int c = ans[i].size();
    if (c == 1)
      dense += 1.0;
    else if (c >= 2)
      dense += (double)ein[i] * 2.0 / (1LL * c * (c - 1));
    else
      assert(false);
  }
  dense = 0.5 * (dense / k - (double)k / n);
  double q = modularity + dense;
  // cerr << q << endl;
  return (q + 1.0) * 1e5;
}

vector<vector<int>> graph;

void output(vector<vector<int>> & ans, string filename) {
  ofstream of(filename);
  for (auto & v : ans) {
    for (int i = 0; i < (int)v.size(); ++i) {
      of << v[i] << (i+1 == (int)v.size() ? '\n' : ' ');
    }
  }
}

vector<vector<int>> greedy_bfs(int k) {
  vector<vector<int>> ret(k, vector<int>());
  int n = graph.size();
  vector<int> col(n, -1);
  queue<int> que;
  set<int> starts;
  while ((int)starts.size() < k) {
    int v = rng() % n;
    if (starts.count(v)) continue;
    que.push(v);
    col[v] = (int)starts.size();
    starts.insert(v);
  }
  while (!que.empty()) {
    int v = que.front();
    ret[col[v]].push_back(v);
    que.pop();
    for (int u : graph[v]) {
      if (col[u] != -1) continue;
      col[u] = col[v];
      que.push(u);
    }
  }
  return ret;
}

int main(int argc, char ** argv) {

  string outfile = "a.out";
  if (argc > 1) {
    outfile = argv[1];
  }
  vector<pair<int, int>> edges;
  int u, v;
  int n = 0;
  while (cin >> u >> v) {
    edges.emplace_back(u, v);
    n = max(n, u+1);
    n = max(n, v+1);
  }
  vector<int> din(n, 0);
  for (auto e : edges) {
    tie(u, v) = e;
    ++din[u], ++din[v];
  }
  cerr << " edges size: " << edges.size() << endl;
  stats(din, "degree");
  vector<int> com(n, -1);
  int m = edges.size();
  graph.assign(n, vector<int>());
  for (auto & e : edges) {
    tie(u, v) = e;
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
  }
  vector<vector<int>> ans;
  double best = -1e9;
  cerr << setprecision(5) << fixed;
  for (int k = 1; k * 2 <= n; k *= 2) {
    for (int i = 0; i < min(10, k); ++i) {
      int cur = k + i * (k / min(10, k));
      vector<vector<int>> res = greedy_bfs(cur);
      double cost = score(graph, res);
      if (cost > best) {
        best = cost;
        ans.swap(res);
        cerr << cur << " " << best << " found !" << endl;
        output(ans, outfile);
      }
    }
  }
  return 0;
}
