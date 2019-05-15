#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int b[N], g[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i)
    scanf("%d", b+i);
  for (int i = 0; i < m; ++i)
    scanf("%d", g+i);
  sort(b, b+n);
  sort(g, g+m);
  if (b[n-1] > g[0]) {
    puts("-1");
    return 0;
  }
  long long ans = 0;
  for (int i = 0; i < n-2; ++i) {
    ans += 1LL * m * b[i];
  }
  if (g[0] == b[n-1])
    ans += b[n-2] * 1LL * m;
  else
    ans += b[n-2] * 1LL * (m-1) + b[n-1];
  for (int i = 0; i < m; ++i)
    ans += g[i];
  cout << ans << endl;
  return 0;
}
