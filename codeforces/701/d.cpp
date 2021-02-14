#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
  return a ? gcd(b % a, a) : b;
}

long long lcm(long long a, long long b) {
  return (a / gcd(a, b)) * b;
}

int main() {
  const int maxi = 1e6;
  vector<int> all;
  for (int i = 1; ; ++i) {
    long long now = i;
    for (int j = 0; j < 3; ++j)
      now *= i;
    if (now > maxi)
      break;
    all.push_back(now);
    // cerr << i << " " << now << endl;
  }
  long long now = 1;
  for (int i = 1; i <= 16; ++i) {
    now = lcm(now, i);
    // cerr << i << " " << now << endl;
  }
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int a;
      scanf("%d", &a);
      int ans = now;
      if ((i + j) & 1) {
        ans = now + all[a-1];
      }
      printf("%d%c", ans, j + 1 == m ? '\n' : ' ');
    }
  }
  return 0;
}
