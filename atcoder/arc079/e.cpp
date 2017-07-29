#include <bits/stdc++.h>

using namespace std;

int n;
long long a[55];

long long cek(long long k) {
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    long long cur = a[i] + k;
    if ((cur % (n+1)) == n) return -1;
    sum += cur / (n+1);
  } 
  return sum;
}

bool cek2(long long k) {
  for (long long i = max(k-n, 0LL); i <= k+n; i++)
    if (cek(i) >= i)
      return true;
  return false;
}

int main() {
  scanf("%d", &n);
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  long long ans = sum;
  for (long long i = max(0LL, sum - (n-1) * n); i <= sum; i++)
    if (cek(i) == i)
      ans = min(ans, i);
  cout << ans << endl;
  return 0;
}