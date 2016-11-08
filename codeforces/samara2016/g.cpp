#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
pair< pair< int, int >, int > z[N], a[N];

int ans[N];

int main() {
  int n, m;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    z[i] = {{x, y}, i};
  }
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    a[i] = {{x, y}, i};
  }
  sort(z, z+n);
  sort(a, a+m);
  set < pair<int, int> > st;
  int j = m-1;
  bool ok = true;
  for (int i = n-1; i >= 0; i--) {
    while (j >= 0 && a[j].first.first >= z[i].first.first) {
      st.insert({a[j].first.second, a[j].second});
      j--;
    }
    auto it = st.lower_bound({z[i].first.second, -1});
    if (it == st.end()) {
      ok = false;
      break;
    }
    ans[z[i].second] = it->second+1;
    st.erase(it);
  }
  if (ok) {
    for (int i = 0; i < n; i++)
      printf("%d ", ans[i]);
    printf("\n");
  }
  else
    puts("-1");
  return 0;
}