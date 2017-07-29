#include <bits/stdc++.h>

using namespace std;
long long b[55], a[55]; 

int main() {
  long long k;
  cin >> k;
  int n = 50;
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    b[i] = k/n;
    if ((k % n) > i)
      b[i]++; 
    sum += b[i];
  }
  assert(sum == k);
  for (int i = 0; i < n; i++) {
    a[i] = min(b[i] * (n + 1) - k + n-1, (long long)(1e16 + 1e3));
    assert(a[i] >= 0);
  }
  printf("%d\n", n);
  for (int i = 0; i < n; i++)
    printf("%lld%c", a[i], i == n-1 ? '\n' : ' ');
  return 0;
}