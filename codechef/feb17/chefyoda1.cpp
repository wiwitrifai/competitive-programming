#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 6;
double C[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m, p, k;
    scanf("%d %d %d %d", &n, &m, &p, &k);
    double ans = 0;
    if (p == 0)
      ans = 1;
    else if ((n & 1) == 0 && (m & 1) == 0)
      ans = 1;
    else if ((n & 1) == 1 && (m & 1) == 1)
      ans = 0;
    else {
      int mid = k/2, z = k;
      double now = 1;
      for (int i = 0; i < mid; i++) {
        now *= (double)(k-i)/(i+1);
        while (now > 1 && z > 0) {
          now /= 2;
          z--;
        }
      }
      while (z > 0) now /= 2, z--;
      for (int i = mid; i >= 0; i--) {
        C[i] = C[k-i] = now;
        now *= (double)i/(k-i+1);
      }
      ans = 0;
      for (int i = p; i <= k; i++)
        ans += C[i];
    };
    assert(ans <= 1.000001);
    printf("%.6lf\n", ans);
  }
  return 0;
}