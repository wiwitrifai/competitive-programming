#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int a[N];

int main() {
  int n;
  scanf("%d", &n);
  long long sum = 0;
  for (int i = 0; i < n; i++)
    scanf("%d", a+i), sum += a[i];
  sort(a, a+n);
  long long sub = a[0];
  if (n == 1)
    sub = 0;
  for (int i = 1; i < n-1; i++) {
    if (a[i] > 0)
      break;
    sub += a[i];
  }
  printf("%lld\n", sum - 2LL * sub);
  return 0;
}