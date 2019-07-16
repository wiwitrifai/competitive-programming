#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
  return a ? gcd(b % a, a) : b;
}

const int N = 1e6 + 6;
char s[N], t[N];

int main() {
  int n, m;
  scanf("%d %d %s %s", &n, &m, s, t);
  long long kpk = 1LL * n * (m / gcd(n, m));
  long long step = kpk / m;
  for (int i = 0; i < n; ++i) {
    long long now = (kpk/n) * i;
    // cerr << i << " " << now << endl;
    if (now % step) continue;
    int cur = now / step;
    if (s[i] != t[cur]) {
      kpk = -1;
      break;
    }
  }
  printf("%lld\n", kpk);
  return 0;
}