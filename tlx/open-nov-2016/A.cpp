#include <bits/stdc++.h>

using namespace std;

const int N = 90;

long long fib[N];

int main() {
  fib[0] = 1;
  fib[1] = 2;
  int n = 2;
  for (int i = 2; i < 90; i++) {
    fib[i] = fib[i-1] + fib[i-2];
    n  = i;
    if (fib[i] > 1e18)
      break;
  }
  long long m;
  cin >> m;
  int id = upper_bound(fib, fib+n, m) - fib - 1;
  printf("%d\n", id);
  return 0;
}