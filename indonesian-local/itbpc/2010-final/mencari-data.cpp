#include <bits/stdc++.h>

using namespace std;

multiset<long long> st;

int main() {
  int n, q;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    long long x;
    scanf("%lld", &x);
    st.insert(x);
  }
  assert(st.size() == n);
  scanf("%d", &q);
  while (q--) {
    char cmd[50];
    long long x;
    scanf("%s %lld", cmd, &x);
    if (cmd[0] == 'C') {
      auto it = st.lower_bound(x);
      if (it == st.end())
        puts("-1");
      else
        printf("%lld\n", *it);
    }
    else {
      auto it = st.find(x);
      if (it != st.end())
        st.erase(it);
    }
  }
  return 0;
}