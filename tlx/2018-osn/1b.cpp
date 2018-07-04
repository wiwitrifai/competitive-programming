#include <bits/stdc++.h>

using namespace std;

int main() {
  scanf("%*s");
  long long a, b;
  int q;
  scanf("%lld %lld", &a, &b);
  vector<pair<long long, int> > ans;
  while (b > 0) {
    if (a == 0) break;
    if (a >= b+1) {
      long long r = a / (b+1);
      r -= (a % (b+1)) == 0;
      if (r == 0) break;
      ans.emplace_back(r, 1);
      a -= r * (b+1);
    }
    else {
      long long r = b / a;
      ans.emplace_back(r, 0);
      b -= r * a;
    }
  }
  if (a == 0 || b != 0) {
    puts("TIDAK MUNGKIN");
    return 0;
  }
  else
    puts("MUNGKIN");
  ans.emplace_back(a, 1);
  reverse(ans.begin(), ans.end());
  long long tot = 0;
  for (auto it : ans)
    tot += it.first;
  scanf("%d", &q);
  while (q--) {
    long long l, r;
    scanf("%lld %lld", &l, &r);
    if (r >= tot) {
      puts("DI LUAR BATAS");
      continue;
    }
    long long now = 0;
    for (auto it : ans) {
      if (l < now + it.first && now <= r) {
        long long cnt = min(now+it.first, r+1) - max(l, now);
        for (long long i = 0; i < cnt; ++i)
          printf("%d", it.second);
      }
      now += it.first;
    }
    printf("\n");
  }
  return 0;
}