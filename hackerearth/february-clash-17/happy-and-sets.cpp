#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int main() {
  int n;
  long long ans = 1;
  scanf("%d", &n);
  while (n--) {
    int x;
    scanf("%d", &x);
    ans = (ans * (x + 1)) % mod;
  }
  printf("%lld\n", (ans+mod-1) % mod);

  return 0;
}