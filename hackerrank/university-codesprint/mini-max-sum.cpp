#include <bits/stdc++.h>

using namespace std;

int main() {
  long long a[6], sum = 0;
  for (int i = 0; i < 5; i++)
    cin >> a[i], sum += a[i];
  long long mi = sum-a[0], ma = sum -a[0];
  for (int i = 0; i < 5; i++) {
    mi = min(mi, sum-a[i]);
    ma = max(ma, sum - a[i]);
  }
  printf("%lld %lld\n", mi, ma);

  return 0;
}