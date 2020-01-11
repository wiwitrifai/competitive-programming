#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  set<int> st;
  for (int i = 0; i < n; ++i) {
    st.insert(k + i);
  }
  vector<tuple<int, int, int>> ans;
  int c = k + 3 * n - 1;
  for (int i = n - 1; i >= 0; i -= 2) {
    int b = k + n + i;
    auto it = st.lower_bound(c - b + 1);
    if (it == st.begin()) {
      puts("-1");
      return 0;
    }
    --it;
    int a = *it;
    st.erase(it);
    ans.emplace_back(a, b, c);
    --c;
  }
  for (int i = n - 2; i >= 0; i -= 2) {
    int b = k + n + i;
    auto it = st.lower_bound(c - b + 1);
    if (it == st.begin()) {
      puts("-1");
      return 0;
    }
    --it;
    int a = *it;
    st.erase(it);
    ans.emplace_back(a, b, c);
    --c;
  }
  for (auto it : ans) {
    int a, b, c;
    tie(a, b, c) = it;
    printf("%d %d %d\n", a, b, c);
  }
  return 0;
}
