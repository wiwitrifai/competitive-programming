#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, t;
  scanf("%d %d", &n, &t);
  int ans = -1, best = 1e9;
  for (int i = 0; i < n; ++i) {
    int s, d;
    scanf("%d %d", &s, &d);
    if (s < t) {
      int x = (t - s) / d;
      s += x * d;
    }
    while (s < t) s += d;
    if (s < best) {
      ans = i+1;
      best = s;
    }
  }
  printf("%d\n", ans);
  return 0;
}