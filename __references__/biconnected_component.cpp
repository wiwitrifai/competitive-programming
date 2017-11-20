void dfs(int v, int bef = -1) {
  num[v] = low[v] = counter++;
  for (int u : adj[v]) {
    if (num[u] == -1) {
      edge.emplace_back(v, u);
      if (v == root)
        childroot++;
      dfs(u, v);
      if (childroot > 1 && v == root) {
        artp[v] = 1;
        while (edge.size() > 0) {
          auto it = edge.back(); edge.pop_back();
          block[nblock].push_back(it);
          if (it == make_pair(v, u))
            break;
        }
        nblock++;
      }
      if (low[u] >= num[v] && v != root) {
        artp[v] = 1;
        while (edge.size() > 0) {
          auto it = edge.back(); edge.pop_back();
          block[nblock].push_back(it);
          if (it == make_pair(v, u))
            break;
        }
        nblock++;
      }
      if (low[u] > num[v])
        bridge.emplace_back(u, v);
      low[v] = min(low[v], low[u]);
    }
    else if (bef != u && low[v] > num[u]) {
      low[v] = min(low[v], num[u]);
      edge.emplace_back(v, u);
    }
  }
}

int main() {
  for (int i = 0; i < gr.n; i++) if (gr.num[i] == -1) {
    root = i;
    childroot = 0;
    edge.clear();
    dfs(i);
    artp[i] = childroot > 1;
    if (edge.size() > 0) {
      while (edge.size() > 0) {
        auto it = edge.back(); edge.pop_back();
        block[nblock].push_back(it);
      }
      nblock++;
    }
  }
}