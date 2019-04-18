#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int main() {
  long long ans = 0;
  int n;
  scanf("%d", &n);
  int last = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    int lef = 1, rig = n;
    if (a == last)
      continue;
    else if (last < a)
      lef = last + 1;
    else
      rig = last - 1;
    ans += 1LL * (a - lef + 1) * (rig - a + 1);
    last = a;
  }
  printf("%lld\n", ans);
  return 0;
}
