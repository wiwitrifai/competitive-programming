#include <bits/stdc++.h>

using namespace std;

bool check(long long x) {
  long long c = x;
  while (c) {
    int d = c % 10;
    c /= 10;
    if (d && x % d) {
      return false;
    }
  }
  return true;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long a;
    scanf("%lld", &a);
    while (!check(a))
      ++a;
    printf("%lld\n", a);
  }
  return 0;
}
