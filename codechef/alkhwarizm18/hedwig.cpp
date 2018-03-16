#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, S = 445;

int c[N], luck[N], ans[N];
int st[N], en[N], node[N];
int cnt[N], cur[N], cntr = 0;

vector<int> g[N];
bool cmp(int le, int ri) {
  int gl = st[le]/S, gr = st[ri]/S;
  if (gl == gr)
    return en[le] < en[ri];
  return gl < gr;
}

void dfs(int v, int par = -1) {
  node[cntr] = c[v];
  st[v] = cntr++;
  for (int u : g[v]) if (u != par) {
    dfs(u, v);
  }
  en[v] = cntr;
}

void add(int col) {
  --cur[cnt[col]];
  ++cnt[col];
  ++cur[cnt[col]];
}
void rem(int col) {
  --cur[cnt[col]];
  --cnt[col];
  ++cur[cnt[col]];
}

int main() {
  int n;
  scanf("%d", &n);
  vector<int> vc;
  for (int i = 0; i < n; ++i) {
    scanf("%d", c+i);
    vc.push_back(c[i]);
  }
  sort(vc.begin(), vc.end());
  vc.erase(unique(vc.begin(), vc.end()), vc.end());
  for (int i = 0; i < n; ++i)
    c[i] = lower_bound(vc.begin(), vc.end(), c[i]) - vc.begin();
  for (int i = 0; i < n; ++i) {
    scanf("%d", luck+i);
  }
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  cntr = 0;
  dfs(0);
  vector<int > que;
  for (int i = 0; i < n; ++i) {
    que.emplace_back(i);
  }
  sort(que.begin(), que.end(), cmp);
  int l = 0, r = 0;
  for (int i : que) {
    while (r < en[i]) add(node[r++]);
    while (l > st[i]) add(node[--l]);
    while (r > en[i]) rem(node[--r]);
    while (l < st[i]) rem(node[l++]);
    if (luck[i] <= n)
      ans[i] = cur[luck[i]];
  }
  for (int i = 0; i < n; ++i)
    printf("%d%c", ans[i], (i == n-1) ? '\n' : ' ');
  return 0;
}