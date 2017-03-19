#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long r, b, p, q;
    cin >> r >> b >> p;
    q = r + b - p;
    long long up = r * p + b * q, down = r + b;
    printf("%.9lf\n", (double)up/down);
  }
  return 0;
}