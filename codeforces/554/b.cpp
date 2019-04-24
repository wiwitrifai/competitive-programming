#include <bits/stdc++.h>

using namespace std;

int main() {
  int x;
  scanf("%d", &x);
  int m = 0;
  while ((1 << m) <= x) ++m;
  int target = (1 << m) - 1;
  int ans = 0;
  vector<int> num;
  assert(x <= target);
  for (int i = 0; x < target; ++i) {
    ++ans;
    if (i & 1) {
      ++x;
    }
    else {
      int k = m;
      while (k > 0 && ((1 << (k-1)) & x) > 0) --k;
      num.push_back(k);
      x ^= (1 << k) - 1;
    }
  }
  printf("%d\n", ans);
  for (int x : num) {
    printf("%d ", x);
  }
  printf("\n");
  return 0;
}
