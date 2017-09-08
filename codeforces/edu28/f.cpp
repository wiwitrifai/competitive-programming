#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int a[N], last[N];

int main() {
  memset(last, -1, sizeof last);
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", a + i);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += 1LL * (i - last[a[i]]) * (n - i);
    last[a[i]] = i;
  }
  cerr << ans << endl;
  ans = 2 * ans - n;
  printf("%.20lf\n", (double) ans / n / n);
  return 0;
}