#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> h(n+2, 0);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &h[i]);
  }
  vector<tuple<int, int, int>> ranges;
  stack<int> st;
  st.push(0);
  for (int i = 1; i <= n + 1; ++i) {
    while (!st.empty() && h[st.top()] > h[i]) {
      int hig = h[st.top()];
      st.pop();
      assert(!st.empty());
      if (!st.empty() && hig > max(h[i], h[st.top()])) {
        ranges.emplace_back(st.top() + 1, i, hig - max(h[i], h[st.top()]));
      }
    }
    st.push(i);
  }
  sort(ranges.begin(), ranges.end(), [&](tuple<int, int, int> & le, tuple<int, int, int> & rig) {
    if (get<0>(le) != get<0>(rig)) {
      return get<0>(le) < get<0>(rig);
    }
    assert(get<1>(le) != get<1>(rig));
    return get<1>(le) > get<1>(rig);
  });
  vector<long long> offset(ranges.size()+1, 0);
  for (int i =  0; i < (int)ranges.size(); ++i) {
    int l, r, height;
    tie(l, r, height) = ranges[i];
    offset[i+1] = offset[i] + 1LL * (r-l) * height;
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    long long k;
    scanf("%lld", &k);
    --k;
    int pos = upper_bound(offset.begin(), offset.end(), k) - offset.begin() - 1;
    k -= offset[pos];
    int l, r;
    tie(l, r, ignore) = ranges[pos];
    k %= (r-l);
    printf("%d\n", l + (int)k);
  }
  return 0;
}
