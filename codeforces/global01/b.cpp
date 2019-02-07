#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int b[N], n, m, k;

int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < n; ++i)
    scanf("%d", b+i);
  for (int i = 0; i < n; ++i)
    b[i] = b[i+1] - b[i] - 1;
  long long ans = n;
  sort(b, b+n-1);
  for (int i = 0; i < n-k; ++i) {
    ans += b[i];
  }
  printf("%lld\n", ans);

  return 0;
}