#include <bits/stdc++.h>

using namespace std;

char buffer[128];

const int S = 202, N = 1e5 + 5;

int go[S][S];

int a[N], cnt[S];
vector<int> pos[S];

int main() {
  int s, l, n;
  scanf("%d %d %d", &s, &l, &n);
  vector<string> species(s);
  for (int i = 0; i < s; ++i) {
    scanf("%s", buffer);
    species[i] = buffer;
  }
  sort(species.begin(), species.end());
  map<string, int> to_node;
  for (int i = 0; i < s; ++i) {
    to_node[species[i]] = i;
  }
  for (int i = 0; i < l; ++i) {
    scanf("%s", buffer);
    int u = to_node[string(buffer)];
    scanf("%s", buffer);
    int v = to_node[string(buffer)];
    go[u][v] = 1;
    go[v][u] = 1;
  }
  for (int i = 0; i < s; ++i) {
    go[i][i] = 1;
    pos[i].push_back(n+i);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%s", buffer);
    a[i] = to_node[string(buffer)];
  }
  for (int i = n-1; i >= 0; --i)
    pos[a[i]].push_back(i);
  for (int i = 0; i < s; ++i) {
    for (int j = 0; j < s; ++j) {
      if (go[i][j]) continue;
      cnt[i] += pos[i].back() > pos[j].back();
    }
  }

  vector<int> ans(n);
  for (int i = 0; i < n; ++i) {
    int v = -1;
    for (int j = 0; j < s; ++j) {
      if (pos[j].back() >= n) continue;
      if (cnt[j] == 0) {
        if (v == -1 || v > j)
          v = j;
      }
    }
    assert(v != -1);
    ans[i] = v;
    for (int j = 0; j < s; ++j) {
      if (go[v][j]) continue;
      cnt[j] -= pos[j].back() > pos[v].back();
    }
    pos[v].pop_back();
    cnt[v] = 0;
    for (int j = 0; j < s; ++j) {
      if (go[v][j]) continue;
      if (pos[j].back() > pos[v].back())
        ++cnt[j];
      else
        ++cnt[v];
    }
  }
  for (int i = 0; i < n; ++i) {
    printf("%s%c", species[ans[i]].c_str(), i+1 == n ? '\n' : ' ');
  }
  return 0;
}
