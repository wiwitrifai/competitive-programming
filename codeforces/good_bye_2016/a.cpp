#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  int ans = 0;
  while (ans < n && k < 240) {
    if (k + 5 * (ans + 1) <= 240)
      ans++, k += 5 * ans;
    else
      break;
  }
  printf("%d\n", ans);
  return 0;
}