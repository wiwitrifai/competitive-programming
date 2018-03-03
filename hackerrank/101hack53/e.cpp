#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
  return a ? gcd(b % a, a) : b;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m, r, c, q;
    scanf("%d %d %d %d %d", &n, &m, &r, &c, &q);
    --r, --c;
    long long nm = 1LL * n * m;
    while (q--) {
      int ty, r1, r2, c1, c2;
      scanf("%d %d %d %d %d", &ty, &r1, &c1, &r2, &c2);
      --r1, --c1;
      if (ty == 1) {
        long long ans = 0;
        for (int i = 0; i < nm; ++i) {
          int x = i % n, y = i % m;
          x += r;
          y += c;
          if (x >= n) x -= n;
          if (y >= m) y -= m;
          if (x < r1) x += n;
          if (y < c1) y += m;
          if (x <= r2 && y <= c2) {
            cerr << i << endl;
            ans += i;
            if (ans >= nm)
              ans -= nm;
          }
        }
        printf("%lld\n", ans);
      }
      else {
        int ansr = 0, ansc = 0;
        for (int i = r1; i <= r2; ++i) {
          int x = (i - r) % n;
          if (x < 0) x += n;
          ansr += gcd(x, n) == 1;
        }
        for (int i = c1; i <= c2; ++i) {
          int x = (i - c) % m;
          if (x < 0) x += m;
          ansc += gcd(x, m) == 1;
        }
        printf("%lld\n", 1LL * ansr * ansc % nm);
      }
    }
  }
  return 0;
}