#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

long long powmod(long long b, long long e) {
  long long r = 1;
  for (; e; e >>= 1, b = b * b % mod)
    if (e & 1)
      r = r * b % mod;
  return r;
}

int main() {
  int n;
  scanf("%d", &n);
  vector<pair<int, int>> events;
  vector<int> len(n);
  for (int i = 0; i < n; ++i) {
    int l, r;
    scanf("%d %d", &l, &r);
    len[i] = r-l + 1;
    events.emplace_back(l, i);
    events.emplace_back(r+1, ~i);
  }
  sort(events.begin(), events.end());
  int last = events[0].first;
  int cnt = 0;
  long long ans = 0, mul = 1, mul1 = 1, other = 1;
  for (int i = 0; i < n; ++i) {
    other = other * len[i] % mod;
  }
  int one = 0;
  for (auto & e : events) {
    if (last < e.first && cnt > 0) {
      long long cur = (mul - mul1) * other % mod;
      if (one > 0) {
        cur = mul * other % mod;
      }
      ans = (ans + cur * (e.first - last)) % mod;
    }
    int id = e.second;
    if (id < 0) {
      id = ~id;
      --cnt;
      one -= len[id] == 1;
      mul = mul * powmod(len[id], mod - 2) % mod;
      other = other * len[id] % mod;
      if (len[id] != 1) {
        mul1 = mul1 * powmod(len[id]-1, mod - 2) % mod;
      }
    } else {
      ++cnt;
      one += len[id] == 1;
      mul = mul * len[id] % mod;
      other = other * powmod(len[id], mod - 2) % mod;
      if (len[id] != 1) {
        mul1 = mul1 * (len[id] - 1) % mod;
      }
    }
    last = e.first;
  }
  ans = ans * powmod(other, mod-2) % mod;
  if (ans < 0)
    ans += mod;
  printf("%lld\n", ans);
  return 0;
}
