#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int lef[N], rig[N];

int p[N];
bool incr[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i)
    scanf("%d", p+i);
  stack<int> st;
  for (int i = 0; i < n; ++i) {
    while (!st.empty() && p[st.top()] <= p[i]) st.pop();
    lef[i] = st.empty() ? -1 : st.top();
    st.push(i);
  }
  while (!st.empty()) st.pop();
  for (int i = n-1; i >= 0; --i) {
    while (!st.empty() && p[st.top()] >= p[i]) st.pop();
    rig[i] = st.empty() ? n : st.top();
    st.push(i);
  }
  int cnt = 1, ada = 0;
  for (int i = 1; i < n; ++i) {
    if (p[i-1] < p[i])
      ++cnt;
    else
      cnt = 1;
    if (incr[i] = (cnt >= k))
      ++ada;
  }
  int ans = !incr[k-1];
  ans += (ada > 0);
  for (int i = 0; i + k < n; ++i) {
    if ((rig[i] > i+k && lef[i+k] < i) || incr[i+k])
      continue;
    ++ans;
  }
  printf("%d\n", ans);
  return 0;
}
