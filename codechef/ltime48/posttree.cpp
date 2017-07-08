#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, LG = 19;

vector< int > g[N];

long long a[N], ans[N];

long long sum[N], pre[N], val[N];
long long sp[LG][N];
void dfs(int v, int depth = 0) {
  if (depth == 0) {
    val[depth] = a[v];
    sum[depth] = a[v];
    for (int i = 0; i < LG; i++)
      sp[i][0] = a[v];
  }
  else {
    sp[0][depth] = a[v];
    for (int i = 0; i + 1 < LG; i++) {
      sp[i+1][depth] = sp[i][depth];
      if ((depth - (1<<i)) >= 0)
        sp[i+1][depth] = min(sp[i+1][depth], sp[i][depth-(1<<i)]);
    }
    val[depth] = a[v];
    int prev = depth;
    for (int i = LG-1; i >= 0; i--) {
      if (prev >= 0 && sp[i][prev] >= a[v])
        prev -= 1 << i;
    }
    prev = max(prev, -1);
    sum[depth] = a[v] * (depth - prev) + (prev >= 0 ? sum[prev] : 0);
  }
  ans[v] = sum[depth];
  for (int u : g[v])
    dfs(u, depth+1);
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int p;
    scanf("%d", &p);
    p--;
    g[p].push_back(i);
  }
  for (int i = 0; i < n; i++)
    scanf("%lld", a+i);
  dfs(0);
  for (int i = 0; i < n; i++) {
    printf("%lld ", ans[i]);
  }
  printf("\n");
  return 0;
}