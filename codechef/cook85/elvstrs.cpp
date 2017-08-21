#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    long long st = 1LL * 2 * n * n * b * b, el = 4LL * n * n * a * a;
    puts((st < el) ? "Stairs" : "Elevator");
  }

  return 0;
}