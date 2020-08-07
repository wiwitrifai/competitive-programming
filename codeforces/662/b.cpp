#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;


multiset<int> mset;
int cnt[N];

void rem_mset(int x) {
  auto it = mset.find(x);
  if (it != mset.end()) {
    mset.erase(it);
  }
}

void add(int x) {
  rem_mset(cnt[x]);
  ++cnt[x];
  mset.insert(cnt[x]);
}

void rem(int x) {
  rem_mset(cnt[x]);
  --cnt[x];
  mset.insert(cnt[x]);
}

void solve() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    add(a);
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    char buff[5];
    int x;
    scanf("%s %d", buff, &x);
    if (buff[0] == '+')
      add(x);
    else
      rem(x);
    if (mset.empty()) {
      puts("NO");
      continue;
    }
    auto it = mset.rbegin();
    if (*it >= 8) {
      puts("YES");
      continue;
    }
    if (*it < 4) {
      puts("NO");
      continue;
    }
    int cur = 0;
    if (*it >= 6)
      ++cur;
    ++it;
    while (it != mset.rend() && cur < 2 && *it >= 2) {
      cur += (*it / 2);
      ++it;
    }
    puts(cur >= 2 ? "YES" : "NO");
  }
}

int main() {
  int tc = 1;
  // scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
