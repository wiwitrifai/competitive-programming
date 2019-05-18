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
  set<pair<long long, long long>> ch;
  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j < n; ++j) {
      long long da = a[i] - a[j], db = b[j] - b[i];
      if (da < 0) {
        da *= -1;
        db *= -1;
      }
      if (da <= 0 || db <= 0)
        continue;
      long long d = gcd(da, db);
      da /= d;
      db /= d;
      ch.insert(make_pair(da, db));
    }
  }
  int ans = (int)ch.size() + 1;
  printf("Case #%d: %d\n", tc, ans);
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
