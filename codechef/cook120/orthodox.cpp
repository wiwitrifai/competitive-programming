#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  scanf("%d", &n);
  vector<long long> a(n);
  for (int i = 0; i < n; ++i)
    scanf("%lld", &a[i]);
  if (n > 65) {
    puts("NO");
    return;
  }
  set<long long> st;
  for (int i = 0; i < n; ++i) {
    long long cur = 0;
    for (int j = i; j < n; ++j) {
      cur |= a[j];
      if (st.count(cur)) {
        puts("NO");
        return;
      }
      st.insert(cur);
    }
  }
  puts("YES");
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
