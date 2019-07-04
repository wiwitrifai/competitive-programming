#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    a[0] = 0;
    for (int i = 0; i < n-1; ++i) {
      scanf("%d", a+i+1);
      a[i+1] += a[i];
    }
    long long ans = 0;
    long long sum = 0;
    for (int i = 1; i <= n; ++i) {
      if (i & 1) {
        ans += sum;
      }
      else {
        int cnt = i / 2;
        sum += a[n-cnt] - a[cnt-1];
        ans += sum;
      }
      printf("%lld%c", ans, i == n ? '\n' : ' ');
    }
  }
  return 0;
}
