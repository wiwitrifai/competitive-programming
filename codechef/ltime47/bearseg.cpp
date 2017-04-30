#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

long long a[N], n, p;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%lld %lld", &n, &p);
    map< long long, int > mp;
    long long now = 0;
    mp[now]++;
    mp[now+p]++;
    long long ans = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
      scanf("%lld", a+i);
      now = (now + a[i]) % p;
      if (now < 0) now += p;
      auto it = mp.upper_bound(now);
      long long r = (now + p- it->first) % p;
      if (r < 0) r += p;
      if (ans < r)
        ans = r, cnt = it->second;
      else if (ans == r)
        cnt += it->second;
      mp[now]++;
      mp[now+p]++;
    }
    printf("%lld %lld\n", ans, cnt);
  }
  return 0;
}