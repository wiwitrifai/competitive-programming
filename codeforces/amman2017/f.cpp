#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int a[N], last[N], to[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> vx;
    for (int i = 0; i < n; i++) {
      scanf("%d", a+i);
      vx.push_back(a[i]);
    }
    sort(vx.begin(), vx.end());
    vx.erase(unique(vx.begin(), vx.end()), vx.end());
    for (int i = 0; i < n; i++)
      a[i] = lower_bound(vx.begin(), vx.end(), a[i]) - vx.begin();
    fill(last, last+n, n);
    for (int i = n-1; i >= 0; i--) {
      to[i] = last[a[i]];
      last[a[i]] = i;
    }
    set<pair<int, int >> st;
    int ans = n;
    for (int i = 0; i < n; i++) {
      auto it = st.find(make_pair(i, a[i]));
      if (it != st.end()) {
        st.erase(it);
        last[a[i]] = to[i];
        ans--;
      }
      else if (st.size() >= k) {
        auto itend = --st.end();
        st.erase(itend);
      }
      st.insert(make_pair(to[i], a[i]));
      last[a[i]] = to[i];
    }
    printf("%d\n", ans);
  }
  return 0;
}