#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

vector<long long> combine(vector<long long> & a, vector<long long> & b) {
  int k = a.size();
  vector<long long> ret(k, 0);
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < k; ++j) {
      int x = i + j;
      if (x >= k)
        x -= k;
      ret[x] = (ret[x] + a[i] * b[j]) % mod;
    }
  }
  return ret;
}

vector<long long> solve(int n, vector<long long> & base) {
  if (n == 0) {
    vector<long long> ret(base.size(), 0);
    ret[0] = 1;
    return ret;
  } else if (n == 1)
    return base;
  int mid = n / 2;
  vector<long long> cur = solve(mid, base);
  cur = combine(cur, cur);
  if (n & 1)
    cur = combine(cur, base);
  return cur;
}

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  vector<long long> cnt(k, 0);
  for (int i = 0; i < n; ++i) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int rig = (c / k) * k;
    for (int j = 0; j < k; ++j) {
      int x = j * j % k;
      x = (x * a + b) % k;
      int l = j, r = rig + j;
      while (l < 1) l += k;
      while (r > c) r -= k;
      if (l > r) continue;
      int cur = (r - l) / k + 1;
      cnt[x] += cur;
    }
  }
  for (int i = 0; i < k; ++i) {
    cnt[i] %= mod;
  }
  vector<long long> ans = solve(m, cnt);
  printf("%lld\n", ans[0]);
  return 0;
}
