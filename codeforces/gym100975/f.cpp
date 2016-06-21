#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 6;
int id[N], res[N];

int main() {
  freopen("calc.in", "r", stdin);
  freopen("calc.out", "w", stdout);
  int n, k;
  scanf("%d%d", &n, &k);
  res[0] = 2 % k;
  memset(id, -1, sizeof id);
  id[res[0]] = 0;
  int a = -1, b = -1;
  for(int i = 1; i<=k; i++) {
    res[i] = (1LL * res[i-1] * res[i-1]) % k;
    if(id[res[i]] >= 0) {
      a = id[res[i]];
      b = i;
      break;
    }
    id[res[i]] = i;
  }
  if(n <= b)
    printf("%d\n", (res[n] + 1) % k);
  else {
    n -= a;
    n %= (b - a);
    printf("%d\n", (res[a + n] + 1) % k);
  }
  return 0;
}