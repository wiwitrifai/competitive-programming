#include <bits/stdc++.h>

using namespace std;

void solve() {
  int a, b;
  scanf("%d %d", &a, &b);
  int ans = 0;
  queue<tuple<int, int, int>> que;
  que.emplace(0, a, b);
  set<pair<int, int>> st;
  while (!que.empty()) {
    tie(ans, a, b) = que.front();
    que.pop();
    if (a == 0)
      break;
    if (!st.count(make_pair(a/b, b))) {
      que.emplace(ans+1, a/b, b);
      st.insert(make_pair(a/b, b));
    }
    if (!st.count(make_pair(a, b+1))) {
      que.emplace(ans+1, a, b+1);
      st.insert(make_pair(a, b+1));
    }
  }
  printf("%d\n", ans);
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
