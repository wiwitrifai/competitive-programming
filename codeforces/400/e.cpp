#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
int euler[N], f[N];
vector< int > prime;
long long totient(long long n) {
  if (n < N)
    return euler[n];
  long long ans = n;
  for (int p : prime) {
    if (n < p)
      break;
    if ((n % p) == 0) {
      ans -= ans/p;
      while ((n % p) == 0) {
        n /= p;
      }
    }
  }
  if (n > 1)
    ans -= ans/n;
  return ans;
}
const int mod = 1e9 + 7;

int main() {
  for (int i = 2; i < N; i++) if (f[i] == 0) {
    f[i] = i;
    prime.push_back(i);
    for (int j = i + i; j < N; j += i) if (f[j] == 0) {
      f[j] = i;
    }
  }
  euler[1] = 1;
  for (int i = 2; i < N; i++) {
    int now = i/f[i], cur = 1, p = f[i];
    while ((now % p) == 0) {
      cur *= p;
      now /= p;
    }
    euler[i] = euler[now] * (p-1) * cur;
  }
  long long n, k;
  cin >> n >> k;
  k = (k + 1) / 2;
  while (k--) {
    n = totient(n);
    if (n == 1)
      break;
  }
  n %= mod;
  if (n < 0)
    n += mod;
  cout << n << endl;

  return 0;
}