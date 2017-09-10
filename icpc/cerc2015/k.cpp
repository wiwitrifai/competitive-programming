#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 5;

int to[N], n;
int d[N], used[N];
set<int> st;

int main() {
  scanf("%d", &n);
  memset(d, 0, sizeof d);
  for (int i = 0; i < 2 * n; ++i) {
    scanf("%d", to+i);
    to[i]--;
    d[to[i]]++;
    st.insert(i);
  }
  vector<int> ans;
  queue<int> que;
  for (int i = 0; i < 2 * n; i++) {
    if (d[i] == 0) {
      que.push(i);
    }
  }
  while (!st.empty()) {
    while (!que.empty()) {
      int v = que.front(); que.pop();
      int u = to[v];
      ans.push_back(v);
      st.erase(v);
      if (st.count(u)) {
        st.erase(u);
        d[to[u]]--;
        if (d[to[u]] == 0 && st.count(to[u])) {
          que.push(to[u]);
        }
      }
    }
    if (!st.empty()) {
      que.push(*st.begin());
    }
  }
  sort(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); i++) {
    printf("%d%c", ans[i] + 1, i + 1 == ans.size() ? '\n' : ' ');
  }
  memset(used, 0, sizeof used);
  memset(d, 0, sizeof d);
  for (int i = 0; i < ans.size(); i++)
    used[ans[i]] = 1, d[to[ans[i]]]++;
  for (int i = 0; i < 2 * n; i++) {
    if (used[i])
      assert(!used[to[i]]);
    else
      assert(d[i] > 0);
  }
  return 0;
}