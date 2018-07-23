#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    long long a = n;
    long long now = n + 1;
    for (int i = 2; 1LL * i * i <= n; ++i) {
      long long b = n/i;
      long long cost = i + b + (i * b < n);
      if (cost < now)
        a = b, now = cost;
    }
    int r = n % a;
    if (r) {
      for (int i = 0; i < r; ++i)
        printf("X");
      printf("D");
    }
    for (int i = r; i < a; ++i)
      printf("X");
    int b = n/a;
    for (int i = 0; i < b; ++i)
      printf("D");
    printf("\n");
  }
  return 0;
}