// time: O(sqrt(N) log log N)
// memory: O(N^0.25)
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

const long long N = 1e18 + 2;
const int N2 = sqrt(N) + 2, N4 = 2e4, M = 2e7;

vector<int> prime;
bitset<N4> notprime;
vector<long long> one, eno;
int mu[N4], m[N4];

void precalc(int K) {
  for (int a = 1; a < K; a += N4) {
    int b = min(a + N4, K);
    for (int j = 0; j < b-a; ++j) {
      mu[j] = 1;
      m[j] = 1;
    }
    for (int p : prime) {
      int pp = p * p;
      if (pp >= b) break;
      for (int i = ((a+pp-1)/pp) * pp; i < b; i += pp)
        mu[i-a] = 0;
      for (int i = ((a+p-1)/p) * p; i < b; i += p)
        mu[i-a] *= -1, m[i-a] *= p;
    }
    for (int i = a; i < b; ++i) {
      int now = mu[i-a];
      if (now == 0) continue;
      if (m[i-a] < i) {
        now = -now;
      }
      if (now > 0) one.push_back(1LL * i * i);
      else eno.push_back(1LL * i * i);
    }
  }
}

long long calc(long long n) {
  long long ans = n;
  for (long long i : eno) {
    if (i > n) break;
    ans += n/i;
  }
  for (long long i : one) {
    if (i > n) break;
    ans -= n/i;
  }
  return ans;
}

int main() {
  for (int i = 2; i < N4; ++i) if (!notprime[i]) {
    prime.push_back(i);
    for (long long j = 1LL * i * i; j < N4; j += i)
      notprime[j] = 1;
  }
  long long n;
  scanf("%lld", &n);
  long long l = n, r = 255054609673752LL;
  precalc(sqrt(r));
  while (l < r) {
    long long mid = (l + r) >> 1;
    long long res = calc(mid);
    if (res >= n)
      r = mid + n - res;
    else
      l = mid + n - res;
  }
  printf("%lld\n", l);
  return 0;
}