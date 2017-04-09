#include <bits/stdc++.h>

using namespace std;

int main() {
  time_t startt = clock();
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    long long n;
    scanf("%lld", &n);
    long long cur = 1, k = 1;
    while ((cur * 10 + 1) <= n) {
      cur = cur * 10 + 1;
      k *= 10;
    }
    long long ans = 0;
    while (k) {
      for (int d = 9; d > 0; d--) {
        long long add = 0;
        for (long long mul = 1; mul <= k; mul *= 10) {
          add = (add * 10 + d);
        }
        if (ans + add <= n) {
          ans += k * d;
          break;
        }
      }
      k /= 10;
    }
    printf("Case #%d: %lld\n", tc, ans);
    cerr << "Case #" << tc << " done! time : " << (double)(clock()-startt) * 1000/CLOCKS_PER_SEC << " ms" << endl; 
  }
  return 0;
}