#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 6;
long long x[N], le[N], ri[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    long long ans = 0;
    le[0] = 0;
    for (int i = 0; i < n; i++) {
      scanf("%lld", x+i);
      le[i+1] = le[i] ^ x[i];
    }
    ri[n-1] = 0;
    for (int i = n-2; i >= 0; i--) {
      ri[i] = ri[i+1] ^ x[i+1];
    }
    ans = 1e18;
    for (int i = 0; i < n; i++)
      ans = min(ans, abs((le[i]^ri[i]) - x[i]));
    printf("%lld\n", ans);
  }

  return 0;
}