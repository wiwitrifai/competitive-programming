#include <bits/stdc++.h>

using namespace std;

int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    long long a, b;
    scanf("%lld %lld", &a, &b);
    int ans = 0;
    while (a != b) {
      ans++;
      if (a > b)
        a >>= 1;
      else
        b >>= 1;
    } 
    printf("%d\n", ans);
  }
  return 0;
}