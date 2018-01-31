#include <bits/stdc++.h>

using namespace std;

int sum(int x) {
  int ret = 0;
  while (x) {
    ret += x % 10;
    x /= 10;
  }
  return ret;
}

int main() {
  int k;
  scanf("%d", &k);
  int ans = 0;
  for (int i = 0, cnt = 0; cnt < k; ++i) {
    if (sum(i) == 10) {
      ans = i;
      ++cnt;
    }
  }
  printf("%d\n", ans);
  return 0;
}