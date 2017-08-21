#include <bits/stdc++.h>

using namespace std;

const int N = 1e6;

int main() {
  int n;
  scanf("%d", &n);
  int ans = 6;
  for (int i = 0; i < N; i++) {
    int now = i, cur = n, cnt = 0, sum = 0;
    for (int j = 0; j < 6;j++) {
      int le = now % 10, ri = cur % 10;
      if (j < 3)
        sum += le;
      else
        sum -= le;
      cnt += le != ri;
      now /= 10;
      cur /= 10;
    }
    if (sum == 0)
      ans = min(ans, cnt);
  }
  printf("%d\n", ans);
  return 0;
}