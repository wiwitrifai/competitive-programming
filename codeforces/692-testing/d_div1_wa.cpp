#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

void solve() {
  int n;
  scanf("%d", &n);
  vector<int> cycles, p(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &p[i]);
    --p[i];
  }
  for (int i = 0; i < n; ++i) {
    if (p[i] < 0)
      continue;
    int now = p[i], cnt = 0;
    while (p[now] != -1) {
      ++cnt;
      int nxt = p[now];
      p[now] = -1;
      now = nxt;
    }
    cycles.emplace_back(cnt);
  }
  int ans2 = 0;
  int ans1 = 1;
  if (n & 1) {
    ans1 = 3;
    for (int i = 0; i < (n - 3) / 2; ++i)
      ans1 = ans1 * 2LL % mod;
    vector<int> cnt(4, 0);
    ans2 = 0;
    for (int x : cycles) {
      int k = x / 4, r = x % 4;
      int cur = k + (r > 0);
      ans2 += cur - 1;
      ++cnt[r];
    }
    if (cnt[3] > 0) {
      --cnt[3];
    } else {
      assert(cnt[1] >= 1 && (cnt[1] & 1));
      bool found = false;
      for (int x : cycles) {
        if (x >= 5 && (x % 4) == 1) {
          found = true;
          break;
        }
      }
      if (found) {
        --cnt[1];
      } else if (cnt[2] > 0) {
        --cnt[2];
        --cnt[1];
        ans2 += 1;
      } else if (cnt[1] >= 3) {
        cnt[1] -= 3;
        ans2 += 2;
      } else {
        cnt[2] += 1;
        cnt[1] -= 1;
        ans2 += 2;
      }
    }
    while (cnt[3] > cnt[1]) {
      ++ans2;
      --cnt[3];
      ++cnt[1];
      ++cnt[2];
    }
    int r = min(cnt[3], cnt[1]);
    ans2 += r;
    cnt[1] -= r;
    cnt[3] -= r;
    ans2 += cnt[1] / 2;
  }
  else {
    ans1 = 1;
    for (int i = 0; i < n / 2; ++i)
      ans1 = ans1 * 2LL % mod;
    vector<int> cnt(4, 0);
    ans2 = 0;
    for (int x : cycles) {
      int k = x / 4, r = x % 4;
      int cur = k + (r > 0);
      ans2 += cur - 1;
      ++cnt[r];
    }
    while (cnt[3] > cnt[1]) {
      ++ans2;
      --cnt[3];
      ++cnt[1];
      ++cnt[2];
    }
    int r = min(cnt[3], cnt[1]);
    ans2 += r;
    cnt[1] -= r;
    cnt[3] -= r;
    ans2 += cnt[1] / 2;
  }
  printf("%d %d\n", ans1, ans2);
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
