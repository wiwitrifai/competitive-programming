#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 6;

bool isp[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int ans = 0;
  n += m;
  for (int i = 2; i <= n; ++i) {
    if (isp[i]) continue;
    ++ans;
    for (int j = i; j <= n; j += i)
      isp[j] = 1;
  }
  printf("%d\n", ans);
  return 0;
}
