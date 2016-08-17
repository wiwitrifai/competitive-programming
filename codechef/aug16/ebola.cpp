#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5, K = 5120;

vector < int > adj[N];
int h[N], w[N], vis[N], kk, n, m, k, s, used[N], selected[N], d[N];
int ans[N], nans;

bool add(int v) {
  if (kk >= K)
    return false;
  int i = kk-1;
  bool ok = true;
  for (i = kk-1; i >= 0 && h[selected[i]] > h[v]; i--) {
    if (i + 2 > h[selected[i]]) {
      ok = false;
      break;
    }
  }
  // printf("%d ok %d %d\n", v, i+2, h[v]);
  if (!ok || (i + 2 > h[v]))
    return false;
  for (i = kk - 1; i >= 0 && h[selected[i]] > h[v]; i--) {
    selected[i+1] = selected[i];
  }
  selected[i+1] = v;
  kk++;
  return true;
}
void erase(int v) {
  int i = 0;
  used[v] = 0;
  kk--;
  while (i < kk && selected[i] != v) i++;
  while (i < kk) {
    selected[i] = selected[i+1];
    i++;
  }
}

void cek() {
  if (kk <= k) {
    nans = kk;
    for (int i = 0; i < kk; i++)
      ans[i] = selected[i];
  }
}

int main() {
  scanf("%d %d %d %d", &n, &m, &k, &s);
  srand(0);
  nans = 0;
  for (int i = 0; i < n; i++)
    ans[i] = rand() % n;
  s--;
  for (int i = 0; i < n; i++)
    scanf("%d", w+i);
  int bobot = 1;
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 0; i < n; i++) {
    d[i] = adj[i].size();
    h[i] = N;
  }
  memset(vis, 0, sizeof vis);
  queue< int > q;
  q.push(s);
  h[s] = 0;
  vis[s] = 1;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int u : adj[v]) if (!vis[u]) {
      h[u] = h[v] + bobot;
      q.push(u);
      vis[u] = 1;
      // printf("h[%d] = %d\n", u, h[u]);
    }
  }
  kk = 0;
  int t = (s + 1) % n;
  for (int i = 0; i < n; i++) 
    if (i != s && h[t] + w[t] < h[i] + w[i])
      t = i;
  used[t] = 1;
  set < pair<int, int > > st;
  st.insert({h[t] + w[t], t});
  memset(vis, 0, sizeof vis);
  while (!st.empty()) {
    auto it = --st.end();
    int v = it->second;
    st.erase(it);
    if (add(v)) {
      for (int u : adj[v]) {
        // printf("%d %d %d %d u\n", u, vis[u], d[u], used[u]);
        vis[u] = 1;
        d[u]--;
        if (d[u] == 0 && used[u])
          erase(u);
        // printf("vis[%d] = %d\n", u, vis[u]);
        if (vis[u]) {
          vis[u] = 1;
          st.insert({h[u] + w[u], u});
        }
      }
    }
    cek();
  }
  // for (int i = 0; i < kk; i++) {
  //   printf("%d | ", selected[i] + 1);
  // }
  // printf("%d\n", kk);
  srand(0);
  for (int i = nans; i < k; i++)
    ans[i] = rand() % n;
  for (int i = 0; i < k; i++)
    printf("%d ", ans[i] + 1);
  printf("\n");
  return 0;
}