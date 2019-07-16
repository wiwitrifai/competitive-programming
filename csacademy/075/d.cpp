#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n;
long long c[N], t[N];
long long ans[N];

int main() {
  scanf("%d", &n);
  vector<pair<long long, int> > st;
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", c+i, t+i);
    st.emplace_back(t[i], i);
  }
  sort(st.begin(), st.end());
  set<int> act;
  long long now = 0;
  for (int i = 0; i < st.size() || act.size() > 0;) {
    if (act.empty()) {
      now = st[i].first;
    }
    while (i < st.size() && now == st[i].first) act.insert(st[i].second), ++i;
    auto it = act.begin();
    int v = *it;
    long long to = now + c[v];
    if (i < st.size())
      to = min(to, st[i].first);
    c[v] -= to-now;
    if (c[v] == 0) {
      act.erase(v);
      ans[v] = to;
    }
    now = to;
  }
  for (int i = 0; i < n; ++i)
    printf("%lld\n", ans[i]);
  return 0;
}