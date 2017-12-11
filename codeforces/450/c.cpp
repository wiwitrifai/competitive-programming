#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 6;

int cnt[N];

int main() {
  int n;
  scanf("%d", &n);
  set<int> st;
  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    auto it = st.lower_bound(x);
    if (it == st.end())
      cnt[x]--;
    else {
      int y = *it;
      it++;
      if (it == st.end())
        cnt[y]++;
    }
    st.insert(x);
  }
  int best = cnt[1];
  int ans = 1;
  for (int i = 2; i <= n; ++i) {
    if (best < cnt[i])
      ans = i, best = cnt[i];
  }
  printf("%d\n", ans);
  return 0;
}