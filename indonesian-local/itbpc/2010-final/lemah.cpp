#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 6;
int d[N];

int main() {
  int n;
  scanf("%d %*d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    d[u]++;
    d[v]++;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++)
    ans += d[i] == 1;
  printf("%d\n", ans);
  return 0;
}