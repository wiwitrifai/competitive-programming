#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int a[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i);
  sort(a, a+n);
  int ans = n;
  for (int i = 0, j = i; i < n; ++i) {
    while (j < n && a[j] <= a[i]) ++j;
    if (j < n && a[j] > a[i] && a[i] + k >= a[j])
      --ans;
  }
  printf("%d\n", ans);
  return 0;
}