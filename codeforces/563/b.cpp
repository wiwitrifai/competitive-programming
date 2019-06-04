#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i);
  int odd = 0;
  for (int i = 0; i < n; ++i)
    odd += a[i] & 1;
  if (odd != 0 && odd != n) {
    sort(a, a+n);
  }
  for (int i = 0; i < n; ++i)
    printf("%d%c", a[i], i == n-1 ? '\n' : ' ');

  return 0;
}
