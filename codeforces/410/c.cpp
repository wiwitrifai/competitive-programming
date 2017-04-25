#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

long long a[N];
long long b[N];
long long gcd(long long x, long long y) {
  return x ? gcd(y % x, x) : y;
}

int main() {
  int n;
  scanf("%d", &n);
  int d = 0;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    a[i] = x;
    b[i] = a[i] & 1;
    d = gcd(d, x);
  }
  if (d > 1) {
    puts("YES\n0");
    return 0;
  }
  if (n == 1 && d == 1) {
    puts("NO");
    return 0;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (b[i] && b[i+1])
      ans++, i++, b[i] = b[i+1] = 0;
    else if (b[i]) {
        ans += 2;
      b[i] = 0;
    }
  }
  printf("YES\n%d\n", ans);
  return 0;
}