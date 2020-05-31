#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9 + 7;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  vector<int> left(n);
  vector<pair<int, int>> pre;
  int sum = 0;
  stack<int> st;
  for (int i = 0; i < n; ++i) {
    while (!st.empty() && a[st.top()] <= a[i]) st.pop();
    while (!pre.empty() && pre.back().second >= sum) pre.pop_back();
    pre.emplace_back(i, sum);
    int le = st.empty() ? 0 : st.top() + 1;
    auto it = lower_bound(pre.begin(), pre.end(), make_pair(le, -inf));
    left[i] = sum - it->second;
    st.push(i);
    sum += a[i];
  }
  while (!st.empty()) st.pop();
  pre.clear();

  int ans = 0;
  sum = 0;
  for (int i = n-1; i >= 0; --i) {
    while (!st.empty() && a[st.top()] < a[i]) st.pop();
    while (!pre.empty() && pre.back().second >= sum) pre.pop_back();
    pre.emplace_back(-i, sum);
    int le = st.empty() ? n-1 : st.top() - 1;
    auto it = lower_bound(pre.begin(), pre.end(), make_pair(-le, -inf));
    ans = max(ans, left[i] + (sum - it->second));
    st.push(i);
    sum += a[i];
  }

  printf("%d\n", ans);
  return 0;
}
