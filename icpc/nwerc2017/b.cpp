#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  int cnt = 0, ans = 0;
  while (cnt < n) {
    cnt += 3;
    if (ans)
      cnt -= 2;
    ++ans;
  }
  printf("%d\n", ans);
  return 0;
}