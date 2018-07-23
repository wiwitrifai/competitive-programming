#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    set<int> st;
    scanf("%d", &n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      int x;
      scanf("%d", &x);
      ans += st.count(x);
      st.insert(x);
    }
    printf("%d\n", ans);
  }

  return 0;
}