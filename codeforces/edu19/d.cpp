#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, inf = 1e9 + 7;
int n, val[N], l[N], r[N];
bool used[N];

set < int > st;

void dfs(int v, int mi = -1, int ma = inf) {
  if (val[v] > mi && val[v] < ma)
    st.insert(val[v]);
  if (l[v] != -1)
    dfs(l[v], mi, min(ma, val[v]));
  if (r[v] != -1)
    dfs(r[v], max(mi, val[v]), ma);
}

int main() {
  scanf("%d", &n, &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d %d", val+i, l+i, r+i);
    if (l[i] != -1)
      used[l[i]] = 1;
    if (r[i] != -1)
      used[r[i]] = 1;
  }
  int root = -1;
  for (int i = 1; i <= n; i++)
    if (!used[i])
      root = i;
  dfs(root);
  int ans = 0;
  for (int i = 1; i <= n; i++)
    ans += !st.count(val[i]);
  printf("%d\n", ans);
  return 0;
}