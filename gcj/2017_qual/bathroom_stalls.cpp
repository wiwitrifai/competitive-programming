#include <bits/stdc++.h>

using namespace std;

map< long long, long long > mp;

int main() {
  time_t startt = clock();
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    long long n, k;
    scanf("%lld %lld", &n, &k);
    long long ansmin = 0, ansmax = 0;
    mp.clear();
    mp[n] = 1;
    while (k > 0 && !mp.empty()) {
      auto it = --mp.end();
      long long cur = it->first, cnt = it->second;
      mp.erase(it);
      k -= cnt;
      if (cur & 1) {
        cur /= 2;
        ansmin = ansmax = cur;
        mp[cur] += 2 * cnt;
      }
      else {
        cur /= 2;
        ansmin = cur-1;
        ansmax = cur;
        mp[cur-1] += cnt;
        mp[cur] += cnt;
      }
    }
    printf("Case #%d: %lld %lld\n", tc, ansmax, ansmin);
    cerr << "Case #" << tc << " done! time : " << (double)(clock()-startt) * 1000/CLOCKS_PER_SEC << " ms" << endl; 
  }
  return 0;
}