#include <bits/stdc++.h>

using namespace std;

const int N = 333;

long long gcd(long long a, long long b) {
  return a ? gcd(b % a, a) : b;
}

long long a[N], b[N];

void solve(int tc) {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%lld %lld", a+i, b+i);
  }
  typedef pair<long long, long long> Fraction;
  Fraction lower = {-1, -1}, upper = {-1, -1};
  auto cmp = [](Fraction lef, Fraction rig) {
    assert(lef.second > 0 && rig.second > 0);
    return lef.first * rig.second < rig.first * lef.second;
  };
  for (int i = 0; i+1 < n; ++i) {
    if (b[i] == b[i+1]) {
      if (a[i] > a[i+1]) {
        printf("Case #%d: IMPOSSIBLE\n", tc);
        return;
      }
      continue;
    }
    if (b[i] < b[i+1]) {
      long long d = b[i+1]-b[i], u = a[i]-a[i+1];
      if (u <= 0)
        continue;
      Fraction now = make_pair(u, d);
      if (lower.second < 0 || cmp(lower, now))
        lower = now;
    }
    else {
      long long d = b[i] - b[i+1], u = a[i+1] - a[i];
      if (u <= 0) {
        printf("Case #%d: IMPOSSIBLE\n", tc);
        return;
      }
      Fraction now = make_pair(u, d);
      if (upper.second < 0 || cmp(now, upper))
        upper = now;
    }
  }
  if (lower.second < 0 && upper.second < 0) {
    printf("Case #%d: 1 1\n", tc);
  }
  else if (upper.second < 0) {
    long long x = 1LL;
    long long y = (lower.first * x + lower.second - 1) / lower.second;
    while (!cmp(lower, make_pair(y, x))) ++y;
    printf("Case #%d: %lld %lld\n", tc, x, y);
  }
  else if (lower.second < 0) {
    long long x = (upper.second + upper.first - 1) / upper.first;
    x = max(x, 1LL);
    long long y = 1LL;
    while (!cmp(make_pair(y, x), upper)) ++x;
    printf("Case #%d: %lld %lld\n", tc, x, y);
  }
  else {
    if (!cmp(lower, upper)) {
      printf("Case #%d: IMPOSSIBLE\n", tc);
      return;
    }
    long long x = 1;
    while (true) {
      long long y = upper.first * x / upper.second;
      if (y * upper.second == upper.first * x)
        --y;
      if (lower.first * x < lower.second * y) {
        break;
      }
      ++y;
      long long tmpx = x;
      x = (y * upper.second + upper.first - 1) / upper.first;
      while (!cmp(make_pair(y, x), upper)) ++x;
      x = max(tmpx, x);
    }
    long long y = (lower.first * x + lower.second - 1) / lower.second;
    while (!cmp(lower, make_pair(y, x))) ++y;
    printf("Case #%d: %lld %lld\n", tc, x, y);
  }
}

int main() {
  time_t startt = clock();
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    solve(tc);
    cerr << "~ #" << tc << " done! time : " << (double)(clock()-startt)/CLOCKS_PER_SEC << " s" << endl;
  }
  return 0;
}
