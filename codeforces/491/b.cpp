#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  int tot = 0;
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i), a[i] *= 10, tot += a[i];
  sort(a, a+n);
  int mi = 45 * n;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (tot >= mi) break;
    ++ans;
    tot += 50 - a[i];
  }
  printf("%d\n", ans);
  return 0;
}