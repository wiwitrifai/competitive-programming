#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  scanf("%d", &n);
  vector<int> x(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &x[i]);
  sort(x.begin(), x.end());
  set<int> st;
  for (int i = 0; i < n; ++i)
    for (int j = i+1; j < n; ++j) {
      st.insert(abs(x[j] - x[i]));
    }
  printf("%d\n", (int)st.size());
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
