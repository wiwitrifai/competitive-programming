#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector<pair<long long, long long>> all;
  map<pair<long long, long long>, int> counts;
  vector<int> prime;
  const int N = 1e5 + 5;
  vector<int> flag(N, 0);
  for (int i = 2; i < N; ++i) {
    if (flag[i]) continue;
    prime.push_back(i);
    for (int j = i; j < N; j += i)
      if (flag[j] == 0)
        flag[j] = i;
  }
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    long long a;
    scanf("%lld", &a);
    long long x = 1, y = 1;
    auto process = [&](long long p) {
      int cnt = 0;
      while ((a % p) == 0) {
        a /= p;
        ++cnt;
      }
      cnt %= 3;
      if (cnt == 2)
        x *= p;
      else if (cnt == 1)
        y *= p;
    };
    for (auto p : prime) {
      if (a < N) break;
      if (a % p) continue;
      process(p);
    }
    if (a >= N) {
      ++ans;
      continue;
    }
    while (a > 1) {
      int p = flag[a];
      process(p);
    }
    pair<long long, long long> cur = make_pair(x, y);
    ++counts[cur];
  }
  for (auto it : counts) {
    auto p = it.first;
    auto c = it.second;
    auto q = make_pair(p.second, p.first);
    if (p.first == p.second) {
      ++ans;
      continue;
    }
    auto res = counts.find(q);
    if (res != counts.end()) {
      if (p.first > p.second) continue;
      ans += max(c, res->second);
    }
    else {
      ans += c;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
