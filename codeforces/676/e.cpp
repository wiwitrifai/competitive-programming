#include <bits/stdc++.h>

using namespace std;

void observe() {
  int n = 18;
  vector<set<string>> st(n + 1);
  st[1].insert("1");
  for (int i = 2; i <= n; ++i) {
    for (int j = 1; j < i; ++j) {
      for (auto a : st[j]) {
        for (auto b : st[i-j]) {
          string res = a + b;
          for (int k = 0; k < (int)res.size(); ++k) {
            res[k] = '1' - (res[k] - '0');
          }
          st[i].insert(res);
        }
      }
    }
    cerr << " i = " << i << endl;
    for (auto  s : st[i]) {
      bool ok = true;
      for (int j = 0; j + 1 < (int)s.size(); ++j) {
        ok &= s[j] != s[j+1];
      }
      if (ok)
        cerr << s << endl;
    }
    int nmask = 1 << i;
    int r = (2 - i) % 3;
    if (r < 0)
      r += 3;
    cerr << " not exist " << " " << r << endl;
    for (int mask = 0; mask < nmask; ++mask) {
      string cur = "";
      for (int j = 0; j < i; ++j) {
        cur.push_back('0' + ((mask >> j) & 1));
      }
      if ((__builtin_popcount(mask) % 3) != r) {
        assert(!st[i].count(cur));
        continue;
      }
      if (st[i].count(cur)) continue;
      cerr << cur << endl;
    }
  }
  exit(0);
}
const long long inf = 1e18;

long long dp[3][2][2], tmp[3][2][2];

void upd(long long & var, long long val) {
  if (var < val)
    var = val;
}

int main() {
  // observe();
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 2; ++j) {
      for (int k = 0; k < 2; ++k) {
        dp[i][j][k] = -inf;
      }
    }
  }
  dp[1][0][1] = a[0];
  dp[0][0][0] = -a[0];
  for (int i = 1; i < n; ++i) {
    for (int r = 0; r < 3; ++r) {
      for (int ok = 0; ok < 2; ++ok) {
        for (int last = 0; last < 2; ++last) {
          tmp[r][ok][last] = dp[r][ok][last];
          dp[r][ok][last] = -inf;
        }
      }
    }
    for (int r = 0; r < 3; ++r) {
      for (int ok = 0; ok < 2; ++ok) {
        for (int last = 0; last < 2; ++last) {
          long long cur = tmp[r][ok][last];
          if (cur <= -inf) continue;
          upd(dp[(r+1) % 3][ok | (last == 1)][1], cur + a[i]);
          upd(dp[r][ok | (last == 0)][0], cur - a[i]);
        }
      }
    }
  }
  int r = (2 - n) % 3;
  if (r < 0)
    r += 3;
  long long ans = max(dp[r][1][0], dp[r][1][1]);
  if (n == 1)
    ans = a[0];
  printf("%lld\n", ans);
  return 0;
}
