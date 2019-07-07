#include <bits/stdc++.h>

using namespace std;

int main() {
  long long r;
  scanf("%lld", &r);
  for (int x = 1; 1LL * x * x <= r; ++x) {
    long long a = 2LL * x, b = 1LL * x * x + x + 1;
    long long c = r - b;
    if (c <= 0) break;
    if (c % a) continue;
    long long y = c / a;
    cout << x << " " << y << endl;
    return 0;
  }
  puts("NO");
  return 0;
}
