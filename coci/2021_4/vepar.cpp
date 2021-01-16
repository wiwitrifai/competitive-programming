#include <bits/stdc++.h>

using namespace std;

const int N = 1e7 + 7;

bool iscomposite[N];
vector<int> primes;

int calc(int p, int n) {
  int ret = 0;
  while (n) {
    n /= p;
    ret += n;
  }
  return ret;
}

int main() {
  for (int i = 2; i < N; ++i) {
    if (iscomposite[i]) continue;
    primes.push_back(i);
    for (int j = i + i; j < N; j += i)
      iscomposite[j] = true;
  }
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int m = max(b, d);
    bool ok = true;
    --a, --c;
    for (int p : primes) {
      if (p > m) break;
      int cnt = calc(p, d) - calc(p, c) - calc(p, b) + calc(p, a);
      if (cnt < 0) {
        ok = false;
        break;
      }
    }
    puts(ok ? "DA" : "NE");
  }
  return 0;
}
