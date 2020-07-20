#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, h, m, k;
  scanf("%d %d %d %d", &n, &h, &m, &k);
  int mod = m / 2;
  vector<pair<int, int>> v;
  vector<int> cand;
  for (int i = 0; i < n; ++i) {
    int hh, mm;
    scanf("%d %d", &hh, &mm);
    long long now = mm;
    now %= mod;
    v.emplace_back(now, i);
    int cur = (now + mod - 1) % mod;
    if (cur < 0)
      cur += mod;
    for (int j = 0; j < 3; ++j) {
      cand.push_back((cur + j) % mod);
    }
    cur = (now + mod - k - 1) % mod;
    if (cur < 0)
      cur += mod;
    for (int j = 0; j < 3; ++j) {
      cand.push_back((cur + j) % mod);
    }
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n; ++i)
    v.emplace_back(v[i].first + mod, v[i].second);
  sort(cand.begin(), cand.end());
  cand.erase(unique(cand.begin(), cand.end()), cand.end());
  int r = 0, l = 0;
  int anst = -1, best = n + 1;
  for (int t : cand) {
    while (r < 2 * n && v[r].first < t + k) {
      ++r;
    }
    while (l < r && v[l].first <= t) {
      ++l;
    }
    if (r-l < best) {
      best = r - l;
      anst = t;
    }
  }
  printf("%d %d\n", best, (anst + k) % mod);
  for (int i = 0; i < 2*n; ++i) {
    if (anst < v[i].first && v[i].first < anst + k) {
      printf("%d ", v[i].second + 1);
    }
  }
  printf("\n");
}

int main() {
  int tc = 1;
  // scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
