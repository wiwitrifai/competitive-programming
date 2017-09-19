#include <bits/stdc++.h>

using namespace std;

int n;
long long k;

void solve(int d) {
  while (n && k >= d) {
    n--;
    k -= d;
    printf("(");
    if (n && k >= d+1)
      solve(d+1);
    printf(")");
  }
}

int main() {
  cin >> n >> k;
  if (1LL * n * (n-1) / 2 < k) {
    puts("Impossible");
    return 0;
  }
  solve(0);
  printf("\n");
  return 0;
}