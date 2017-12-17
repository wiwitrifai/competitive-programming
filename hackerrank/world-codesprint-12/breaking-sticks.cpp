#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int isp[N];

vector<int> prime;
long long calc(long long s) {
  vector<int> fac;
  long long cur = s;
  for (int p : prime) {
    if (1LL * p * p > cur) break;
    while ((cur % p) == 0) {
      cur /= p;
      fac.push_back(p);
    }
  }
  long long ans = s;
  reverse(fac.begin(), fac.end());
  if (cur > 1) {
    ans += 1;
  }
  for (int p : fac) {
    ans += cur;
    cur *= p;
  }
  return ans;
}

int main() {
  for (int i = 2; i < N; ++i) if (!isp[i]) {
    for (int j = i+i; j < N; j += i)
      isp[j] = 1;
    prime.push_back(i);
  }
  int n;
  scanf("%d", &n);
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    long long a;
    scanf("%lld", &a);
    ans += calc(a);
  }
  printf("%lld\n", ans);
  return 0;
}