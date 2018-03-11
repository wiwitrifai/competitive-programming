#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  long long ans = 0;
  for (int b = 1; b <= n; ++b) {
    for (int a = 0; a <= n; a += b) {
      int sisa = min(n-a+1, b);
      sisa -= min(sisa, k);
      ans += sisa;
    }
  }
  if (k == 0)
    ans = 1LL * n * n;
  cout << ans << endl;
  return 0;
}