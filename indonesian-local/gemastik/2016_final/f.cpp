#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int s[N];

vector< int > prime;
bitset< N > bs;

int main() {
  bs.set();
  for (int i = 2; i < N; i++) if (bs[i]) {
    prime.push_back(i);
    for (long long j = 1LL * i * i; j < N; j += i)
      bs[j] = 0;
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int s;
      scanf("%d", &s);
      int cnt = 0;
      for (int j = 0; j < prime.size() && 1LL * prime[j] * prime[j] <= s; j++) {
        int p = prime[j];
        while ((s % p) == 0) {
          s /= p;
          cnt++;
        }
      }
      if (s > 1) cnt++;
      ans ^= cnt;
    }
    puts(ans ? "TIDAK" : "YA");
  }
  return 0;
}