#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

int main() {
  time_t startt = clock();
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    long long d, n;
    scanf("%lld %lld", &d, &n);
    double ans = 1e18;
    for (int i = 0; i < n; i++) {
      long long k, s;
      scanf("%lld %lld", &k, &s);
      double r = (double)s * d / (d-k);
      if (i == 0)
        ans = r;
      else
        ans = min(ans, r);
    }
    printf("Case #%d: %.12lf\n", tc, ans);
    cerr << "Case #" << tc << " done! time : " << (double)(clock()-startt) * 1000/CLOCKS_PER_SEC << " ms" << endl;
  }
  return 0;
}