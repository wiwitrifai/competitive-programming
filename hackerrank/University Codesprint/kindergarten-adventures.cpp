#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 6;

int t[N], x[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", t+i);
    if (t[i] >= n)
      continue;
    int add = (i+n-t[i]) % n;
    x[i+1]++;
    x[add+1]--;
    if (add <= i) {
      x[0]++;
    }
  }
  int ans = 0, ma = x[0], now = 0;
  for (int i = 0; i < n; i++) {
    now += x[i];
    if (now > ma)
      ans = i, ma = now;
  }
  printf("%d\n", ans+1);
  return 0;
}