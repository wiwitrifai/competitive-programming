#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

long long a[N];

int main() {
  int n;
  scanf("%d", &n);
  long long sum = 0;
  for (int i = 0;i < n; i++) {
    scanf("%lld", a+i);
    sum += a[i];
  }
  long long cur = 0;
  long long ans = 0;
  for (int i = 0; i < n-1; i++) {
    cur += a[i];
    sum -= a[i];
    if (i == 0)
      ans = abs(cur-sum);
    else
      ans = min(ans, abs(cur-sum));
  }
  cout << ans << endl;

  return 0;
}