#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], n;

int main() {
  scanf("%d", &n);
  int zero = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
    zero += a[i] == 0;
  }
  int ans = 0, prev = n-zero;
  for (int i = 0; i < zero; i++) {
    ans += a[n-1-i];
  }
  int cur = ans;
  for (int i = 0; i < n; i++, prev = (prev + 1) % n) {
    cur += a[i];
    cur -= a[prev];
    ans = min(ans, cur);
  }
  printf("%d\n", ans);
  return 0;
}