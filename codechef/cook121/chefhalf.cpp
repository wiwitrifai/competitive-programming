#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5, LG = 19;

int val[N];

void solve() {
  int n;
  scanf("%d", &n);
  vector<pair<int, int>> values(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", val+i);
    values[i] = {val[i], i};
  }
  sort(values.begin(), values.end());
  set<int> up, down;
  up.insert(-1);
  up.insert(n);
  for (int i = -1; i <= n; ++i)
    down.insert(i);
  auto get_lef = [&](int x, set<int> & st) {
    auto it = st.lower_bound(x);
    --it;
    return *it + 1;
  };
  auto get_rig = [&](int x, set<int> & st) {
    auto it = st.lower_bound(x+1);
    return *it - 1;
  };
  long long ans = 0;
  for (int i = 0; i < n;) {
    int now = values[i].first;
    int til = i;
    while (til < n && values[til].first == now) {
      down.erase(values[til].second);
      up.insert(values[til].second);
      ++til;
    }
    int last = 0;
    auto calc = [&](int a, int b, int c) {
      if (a < 0 || b < 0 || c < 0)
        return 0;
      int l = 0, r = a;
      l = max(b-c, l);
      r = min(r, b);
      if (l > r)
        return 0;
      return r-l + 1;
    };
    for (; i < til; ++i) {
      int pos = values[i].second;
      int lef = get_lef(pos, down), rig = get_rig(pos, down);
      int lef0 = get_lef(lef, up), rig0 = get_rig(rig, up);
      int lef1 = get_lef(lef0, down), rig1 = get_rig(rig0, down);
      lef = max(lef, last);
      lef0 = max(lef0, last);
      lef1 = max(lef1, last);
      int l0 = lef - lef0, l1 = lef0 - lef1, ll = pos - lef;
      int r0 = rig0 - rig, r1 = rig1 - rig0, rr = rig - pos;
      ans += max(0, min(l0, ll + 1 + rr) - ll);
      ans += max(0, min(r0, ll + 1 + rr) - rr);
      ans += calc(l0-1, ll + rr - 1, r0-1);
      if (l0 > ll +1) {
        int a = l1, b = l0, c = ll + 1 + rr;
        b -= ll + 2;
        c -= ll + 1;
        a -= 1;
        if (a >= 0 && b >= 0 && c >= 0) {
          ans += calc(a, b, c);
        }
      }
      if (r0 > rr+1) {
        int a = ll+1+rr, b = r0, c = r1;
        b -= rr + 2;
        a -= rr + 1;
        c -= 1;
        if (a >= 0 && b >= 0 && c >= 0) {
          ans += calc(a, b, c);
        }
      }
      last = pos;
    }
  }
  printf("%lld\n", ans);
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
