// Verdict: WA

#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, p;
  scanf("%d %d", &p, &n);
  vector<int> s(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &s[i]);
    --s[i];
  }
  int k;
  scanf("%d", &k);
  vector<bool> used(n, false);
  vector<bool> pused(p, false);
  vector<pair<int, int>> edges;
  for (int i = 0; i < k; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    --a, --b;
    edges.emplace_back(a, b);
    used[a] = 1;
    used[b] = 1;
    pused[s[a]] = 1;
    pused[s[b]] = 1;
  }
  vector<int> ans;
  for (int i = 0; i < n; ++i) {
    if (used[i]) continue;
    if (pused[s[i]]) continue;
    pused[s[i]] = 1;
    ans.push_back(i);
  }
  vector<int> ids;
  for (int i = 0; i < n; ++i) {
    if (used[i]) {
      ids.push_back(i);
    }
  }
  sort(ids.begin(), ids.end(), [&](int l, int r) {
    return s[l] < s[r];
  });
  vector<int> rev(n, -1);
  vector<int> vs(ids.size());
  for (int i = 0; i < (int)ids.size(); ++i) {
    rev[ids[i]] = i;
    vs[i] = s[ids[i]];
  }
  for (auto & e : edges) {
    e.first = rev[e.first];
    e.second = rev[e.second];
  }
  vector<long long> mask(ids.size());
  n = ids.size();
  for (int i = 0; i < n; ++i) {
    mask[i] = (1LL << i);
    for (int j = 0; j < n; ++j) {
      if (vs[i] != vs[j]) {
        mask[i] |= 1LL << j;
      }
    }
  }
  for (auto & e : edges) {
    int u, v;
    tie(u, v) = e;
    mask[u] ^= 1LL << v;
    mask[v] ^= 1LL << u;
  }
  int best = 0;
  long long best_mask = 0;
  auto backtrack = [&](auto self, int i, long long cur, long long fix) {
    int cnt = __builtin_popcountll(cur);
    if (cnt <= best) return;
    if (i == n) {
      if (cnt > best) {
        best = cnt;
        best_mask = cur;
      }
      return;
    }
    long long now = 1LL << i;
    long long mix = cur & mask[i];
    fix |= now;
    if (!((mix^cur) & fix) && (mix & now)) {
      self(self, i+1, mix, fix);
    }
    cur &= ~now;
    self(self, i+1, cur, fix);
    return;
  };
  backtrack(backtrack, 0, (1LL << n) - 1, 0);
  for (int i = 0; i < n; ++i) {
    long long now = 1LL << i;
    if (now & best_mask)
      ans.push_back(ids[i]);
  }
  sort(ans.begin(), ans.end());
  printf("%d\n", (int)ans.size());
  for (int i = 0; i < (int)ans.size(); ++i) {
    printf("%d%c", ans[i] + 1, i+1 == (int)ans.size() ? '\n' : ' '); 
  }
  return 0;
}
