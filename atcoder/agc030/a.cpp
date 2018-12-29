#include <bits/stdc++.h>

using namespace std;

int main() {
  long long a, b, c;
  scanf("%lld %lld %lld", &a, &b, &c);
  c = min(c, a+b+1);
  printf("%lld\n", b+c);
  return 0;
}