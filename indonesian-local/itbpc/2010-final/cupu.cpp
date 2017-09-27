#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  long long sum =0;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    sum += x;
  }
  printf("%lld\n", (sum + 23) / 24);
  return 0;
}