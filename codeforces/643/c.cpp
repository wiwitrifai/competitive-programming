#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b, c, d;
  scanf("%d %d %d %d", &a, &b, &c, &d);
  long long ans = 0, cnt = 0;
  for (int i = b; i <= c; ++i) {
    int up = i + a - 1;
    up = min(up, d);
    if (up >= c) {
      cnt += up - c + 1;
    }
  } 
  ans += cnt;
  for (int i = a; i < b; ++i) {
    int le = b, ri = c;
    le = max(le, c - i);
    ri = min(ri, d - i);
    if (le <= ri) {
      cnt += ri- le + 1;
    }
    ans += cnt;
  }
  printf("%lld\n", ans);
  return 0;
}
