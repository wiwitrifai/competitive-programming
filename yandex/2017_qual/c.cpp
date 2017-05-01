#include <bits/stdc++.h>

using namespace std;

const int N = 100;
long long a[N];
long long ans1, ans2;
vector< int > ch[N];
void dfs(int v, int depth) {
  ans1 += a[v];
  ans2 += a[v] * (1LL << depth);
  for (int u : ch[v])
    dfs(u, depth+1);
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%lld", a+i);
  for (int i = 1; i <= n; i++) {
    int k;
    scanf("%d", &k);
    for (int j = 0; j < k; j++) {
      int x;
      scanf("%d", &x);
      ch[i].push_back(x);
    }
  }
  ans1 = ans2 = 0;
  dfs(1, 0);
  printf("%lld %lld\n", ans1, ans2);
  return 0;
}