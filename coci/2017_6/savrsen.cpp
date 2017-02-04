#include <bits/stdc++.h>

using namespace std;

const int N = 1e7 + 7;

int x[N];

int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  for (int i = 1; i <= b; i++) {
    for (int j = i + i; j <= b; j += i)
        x[j] += i;
  }
  long long ans = 0;
  for (int i = a; i <= b; i++) {
    int d = i - x[i];
    if (d < 0) d = -d;
    ans += d;
  }
  printf("%lld\n", ans);
  return 0;
}