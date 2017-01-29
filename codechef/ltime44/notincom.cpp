#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 7;

int a[N], n, m;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
      scanf("%d", a+i);
    set< int > st;
    for (int i = 0; i < m; i++) {
      int x;
      scanf("%d", &x);
      st.insert(x);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
      if (st.count(a[i]))
        ans++;
    printf("%d\n", ans);
  }
  return 0;
}