#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

long long a[N], b[N], p, q;
const long long inf = 1e17;

int main() {
  int n, m, k;
  scanf("%d %d %lld %lld %d", &n, &m, &p, &q, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", a+i);
  }
  for (int i = 0; i < m; ++i) {
    scanf("%lld", b+i);
  }
  long long ans = -1;
  a[n] = b[m] = inf;
  for (int i = 0; i <= min(n, k); ++i) {
    long long s = a[i] + p;
    int sisa = k - i;
    int pos = lower_bound(b, b+m, s) - b;
    pos = min(pos + sisa, m);
    ans = max(ans, b[pos] + q);
  }
  if (ans >= inf)
    ans = -1;
  cout << ans << endl;
  return 0;
}
