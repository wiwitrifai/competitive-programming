#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i);
  sort(a, a+n);
  int ans = 0;
  for (int i = 0, j = 0; i < n; ++i) {
    while (j < n && a[j] <= a[i]) ++j;
    if (j < n && a[j] > a[i]) {
      ++ans;
      ++j;
    }
  }
  printf("%d\n", ans);
  return 0;
}