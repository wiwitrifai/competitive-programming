#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  int k = 1;
  for (int i = 2; i <= n; ++i) {
    if (a[i]) continue;
    for (int j = i; j <= n; j += i)
      a[j] = k;
    ++k;
  }
  for (int i = 2; i <= n; ++i)
    printf("%d%c", a[i], i == n ? '\n' : ' ');

  return 0;
}
