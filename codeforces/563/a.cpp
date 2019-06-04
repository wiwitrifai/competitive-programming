#include <bits/stdc++.h>

using namespace std;

const int N = 2024;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < 2 * n; ++i)
    scanf("%d", a+i);
  sort(a, a+2 * n);
  long long sum = 0;
  for (int i = 0; i < n; ++i)
    sum += a[i] - a[i+n];
  if (sum == 0) {
    puts("-1");
    return 0;
  }
  for (int i = 0; i < 2 * n; ++i)
    printf("%d%c", a[i], i == 2 * n-1 ? '\n' : ' ');
  return 0;
}
