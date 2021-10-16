#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<pair<int, int>> g, tmp;
  vector<long long> sum(n+2, 0);
  for (int i = 0; i < n; ++i) {
    for (auto & it : g) {
      it.second = gcd(it.second, a[i]);
    }
    g.emplace_back(i, a[i]);
    tmp.clear();
    int last = g[0].second, id = g[0].first;
    for (auto & it : g) {
      if (last == it.second) {
        id = it.first;
      } else {
        tmp.emplace_back(id, last);
        last = it.second;
        id = it.first;
      }
    }
    tmp.emplace_back(id, last);
    g.swap(tmp);
    int from = 0;
    for (auto & it : g) {
      sum[i - it.first+1] += it.second;
      sum[i - from + 1 + 1] -= it.second;
      from = it.first + 1;
    }
  }
  long long ans = 1;
  for (int i = 0; i < n; ++i) {
    sum[i+1] += sum[i];
    sum[i+1] %= mod;
    ans = (ans * sum[i+1]) % mod;
  }
  ans %= mod;
  if (ans < 0)
    ans += mod;
  cout << ans << endl;
  return 0;
}
