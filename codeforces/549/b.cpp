#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, LG = 20;

int p[N], a[N], bef[N], par[N], last[N];
vector<int> child[N];
int sp[LG][N];

vector<int> s;
int n, m, q;

void dfs(int v) {
  s.push_back(v);
  sp[0][v] = (int)s.size() >= n ? s[(int)s.size()-n] : -1;
  for (int u : child[v]) {
    dfs(u);
  }
  s.pop_back();
}

int get(int l, int r) {
  int len = r-l;
  int lg = 31 - __builtin_clz(len);
  return max(sp[lg][l], sp[lg][r-(1<<lg)]);
}


int main() {
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 0; i < n; ++i) {
    scanf("%d", p+i);
    if (i)
      bef[p[i]] = p[i-1];
  }
  bef[p[0]] = p[n-1];
  memset(last, -1, sizeof last);
  for (int i = 0; i < m; ++i) {
    scanf("%d", a+i);
    int now = a[i];
    int pre = bef[now];
    par[i] = last[pre];
    last[now] = i;
    if (par[i] != -1)
      child[par[i]].push_back(i);
  }
  for (int i = 0; i < m; ++i) {
    if (par[i] == -1) {
      s.clear();
      dfs(i);
    }
  }
  for (int i = 0; i + 1 < LG; ++i) {
    for (int j = 0; j + (1 << (i+1)) <= m; ++j) {
      int le = sp[i][j], ri = sp[i][j+(1<<i)];
      sp[i+1][j] = max(le, ri);
    }
  }
  while (q--) {
    int l, r;
    scanf("%d %d", &l, &r);
    --l;
    int res = get(l, r);
    printf("%d", res >= l);
  }
  printf("\n");
  return 0;
}
