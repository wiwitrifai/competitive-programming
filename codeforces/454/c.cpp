#include <bits/stdc++.h>

using namespace std;

int g[100];
int dp[1 << 22];
int n, m;

int cmp(int a, int b) {
  int ca = __builtin_popcount(a), cb =__builtin_popcount(b);
  if (ca < cb) return a;
  return b;
}

int get(int mask) {
  if (mask + 1 == (1 << n)) return 0;
  int & ret = dp[mask];
  if (ret != -1) return ret;
  ret = (1 << n) - 1;  
  for (int i = 0; i < n; ++i) {
    if ((mask & (1 << i)) && (mask | g[i]) != mask) {
      ret = cmp(ret, get(mask | g[i]) | (1 << i));
    }
  }
  return ret;
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--; v--;
    g[u] |= 1 << v;
    g[v] |= 1 << u;
  }
  if (m == (n * (n-1) / 2)) {
    puts("0");
    return 0;
  }
  for (int i= 0; i < n; ++i)
    g[i] |= 1 << i;
  memset(dp, -1, sizeof dp);
  int ans = (1 << n) - 1;
  for (int i = 0; i < n; ++i)
    ans = cmp(ans, get(g[i]) | (1 << i)); 
  printf("%d\n", __builtin_popcount(ans));
  for (int i = 0; i < n; ++i) {
    if (ans & (1 << i)) {
      printf("%d ", i+1);
    }
  }
  printf("\n");
  return 0;
}