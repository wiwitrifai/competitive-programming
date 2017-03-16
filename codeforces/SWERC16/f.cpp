#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n, r[N], p[N], t[N], flat[N], cntr;

long long bit[N];
void upd(int x, long long v) {
  for (; x < N; x += x&(-x))
    bit[x] += v;
}
long long get(int x) {
  long long ret = 0;
  for (; x; x -= x&(-x))
    ret += bit[x];
  return ret;
}
vector< int > child[N], last[N];

long long ans[N];

void dfs(int v) {
  cntr++;
  flat[cntr] = v;
  for (int u : child[v]) {
    dfs(u);
  }
  last[cntr].push_back(v);
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d %d", p+i, r+i, t+i);
    p[i]--;
    if (p[i] >= 0)
      child[p[i]].push_back(i);
  }
  cntr = 0;
  for (int i = 0; i < n; i++) {
    if (p[i] < 0)
      dfs(i);
  }
  memset(ans, 0, sizeof ans);
  for (int i = 1; i <= cntr; i++) {
    int v = flat[i];
    ans[v] -= get(r[v]-1);
    upd(r[v], t[v]);
    for (int u : last[i])
      ans[u] += get(r[u]-1);
  }
  for (int i = 0; i < n; i++)
    printf("%I64d\n", ans[i]);

  return 0;
}