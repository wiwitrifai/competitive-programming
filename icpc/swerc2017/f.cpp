#include <bits/stdc++.h>

using namespace std;

int main() {
  int w, n;
  scanf("%d %d", &w, &n);
  long long tot = 0;
  for (int i = 0; i < n; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    tot += 1LL* a * b;
  }
  printf("%lld\n", (tot + w - 1) / w);

  return 0;
}
