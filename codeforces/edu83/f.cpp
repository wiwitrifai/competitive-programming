#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, x, y, z;
    scanf("%d %d %d %d", &n, &x, &y, &z);
    vector<int> a, b, c;
    a.push_back(0);
    b.push_back(0);
    c.push_back(0);
    map<vector<int>, int> states;
    int from = 0;
    for (int i = 1; ; ++i) {
      set<int> st;
      st.insert(a[max(i-x, 0)]);
      st.insert(b[max(i-y, 0)]);
      st.insert(c[max(i-z, 0)]);
      int p = 0;
      for (int u : st) {
        p += u == p;
      }
      a.push_back(p);
      st.clear();
      st.insert(a[max(i-x, 0)]);
      st.insert(c[max(i-z, 0)]);
      p = 0;
      for (int u : st) {
        p += u == p;
      }
      b.push_back(p);

      st.clear();
      st.insert(a[max(i-x, 0)]);
      st.insert(b[max(i-y, 0)]);
      p = 0;
      for (int u : st) {
        p += u == p;
      }
      c.push_back(p);
      if (i >= 6) {
        vector<int> comb;
        for (int j = 0; j < 6; ++j) {
          comb.push_back(a[i-j]);
          comb.push_back(b[i-j]);
          comb.push_back(c[i-j]);
        }
        if (states.count(comb)) {
          from = states[comb];
          break;
        }
        states[comb] = i;
      }
    }
    int cycle = (int)a.size() - from - 1;
    auto calc = [&](long long p) {
      p = max(p, 0LL);
      if (p < (int)a.size())
        return make_tuple(a[p], b[p], c[p]);
      p -= from;
      p %= cycle;
      p += from;
      return make_tuple(a[p], b[p], c[p]);
    };
    int ans = 0;
    vector<long long> val(n);
    int all = 0;
    for (int i = 0; i < n; ++i) {
      scanf("%lld", &val[i]);
      all ^= get<0>(calc(val[i]));
    }
    for (int i = 0; i < n; ++i) {
      int now = all ^ get<0>(calc(val[i]));
      ans += (now ^ get<0>(calc(val[i]-x))) == 0;
      ans += (now ^ get<1>(calc(val[i]-y))) == 0;
      ans += (now ^ get<2>(calc(val[i]-z))) == 0;
    }
    printf("%d\n", ans);
  }
  return 0;
}
