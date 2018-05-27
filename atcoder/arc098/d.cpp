#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  long long ans = 0;
  int now = 0;
  for (int i = 0, j = 0; i < n; ++i) {
    scanf("%d", a+i);
    while (j < i && (now & a[i]) > 0) {
      now ^= a[j++];
    }
    now ^= a[i];
    ans += i-j+1;
  }
  printf("%lld\n", ans);
  return 0;
}