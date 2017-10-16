#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

bool isp[N];
vector<int> prime;
long long val[N], cur[N];

int main() {
  for (int i = 2; i < N; i++) if (!isp[i]) {
    prime.push_back(i);
    for (long long j = 1LL * i * i; j < N; j += i)
      isp[j] = 1; 
  }
  int t;
  long long a, b;
  scanf("%d %lld %lld", &t, &a, &b);
  for (long long x = a; x <= b; x++)
    val[x-a] = 1, cur[x-a] = x;
  for (int p : prime) {
    for (long long x = (a/p) * p; x <= b; x += p) {
      if (x < a) continue;
      int cnt = 1;
      while ((cur[x-a] % p) == 0) {
        cnt++;
        cur[x-a] /= p;
      }
      val[x-a] *= cnt;
    }
  }
  for (long long x = a; x <= b; x++) {
    val[x-a] *= cur[x-a] > 1 ? 2 : 1;
  }
  while (t--) {
    long long p;
    scanf("%d", &p);
    long long ans = 0;
    for (long long x = a; x <= b; x++) {
      if (x % p) {
        ans += val[x-a];
        continue;
      }
      long long now = x;
      int cnt = 1;
      while ((now % p) == 0) {
        cnt++;
        now /= p;
      }
      ans += val[x-a] / cnt;
    }
    printf("%lld\n", ans);
  }
  return 0;
}