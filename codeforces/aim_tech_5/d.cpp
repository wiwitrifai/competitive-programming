#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7, inf = mod;
char s[1024];

int main() {
  set<int> st;
  int n;
  long long ans = 1;
  scanf("%d", &n);
  int lo = -1, hi = inf;
  for (int i = 0; i < n; ++i) {
    int p;
    scanf("%s %d", s, &p);
    if (s[1] == 'D') {
      st.insert(p);
    }
    else {
      st.erase(p);
      if (p < lo || p > hi) {
        ans = 0;
      }
      else if (p == lo || p == hi) {
        //
      }
      else {
        ans += ans;
        if (ans >= mod)
          ans -= mod;
      }
      auto it = st.lower_bound(p);
      if (it == st.end())
        hi = inf;
      else
        hi = *it;
      if (it == st.begin())
        lo = -1;
      else
        lo = *(--it);
    }
  }
  int cnt = 0;
  for (auto x : st) {
    cnt += lo < x && x < hi;
  }
  ans = 1LL * ans * (cnt + 1) % mod;
  printf("%lld\n", ans);
  return 0;
}