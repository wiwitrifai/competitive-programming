#include <bits/stdc++.h>

using namespace std;

const int N = 202, inf = 1e8;

int main() {
  time_t startt = clock();
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    int n;
    scanf("%d", &n);
    map<long long, int > cnt;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      long long l;
      scanf("%lld", &l);
      cnt[l]++;
    }
    for (auto it = cnt.begin(); it != cnt.end(); it++) {
      if (it->second < 2) continue;
      long long now = it->first;
      long long mul = 1LL * it->second * (it->second - 1)/2, ccnt = 0;
      long long mul3 = mul * (it->second - 2)/3;
      for (map<long long, int>::iterator cur = cnt.begin(), last = cnt.begin(); cur != cnt.end(); cur++) {
        if (cur->first == now) continue;
        while (last != cur && (cur->first-last->first) >= now * 2) {
          if (last->first != now)
            ccnt -= last->second;
          last++;
        }
        if (abs(cur->first-now) < now * 2)
          ans += 1LL * mul3 * cur->second;
        ans += 1LL * ccnt * mul * cur->second;
        ccnt += cur->second;
      }
    }
    printf("Case #%d: %lld\n", tc, ans);
    cerr << "~ #" << tc << " done! time : " << (double)(clock()-startt) * 1000/CLOCKS_PER_SEC << " ms" << endl;
  }
  return 0;
}