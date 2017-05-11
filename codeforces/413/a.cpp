#include <bits/stdc++.h>

using namespace std;

int main() {
  int t, d, n, k;
  scanf("%d %d %d %d", &n, &t, &k, &d);
  int bef = (n + k-1)/k * t;
  int now = 0, sec = d;
  while (n > 0) {
    if (now < sec) {
      now += t;
      n -= min(n, k);
    }
    else {
      sec += t;
      n -= min(n, k);
    }
  }
  puts(bef > max(now, sec) ? "YES" : "NO");


  return 0;
}