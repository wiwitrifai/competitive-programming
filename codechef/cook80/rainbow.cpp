#include <bits/stdc++.h>

using namespace std;

const int N = 60;

int c[N][N], live[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      live[i] = 1;
      set< int > st;
      for (int j = 0; j < n; j++) {
        scanf("%d", c[i]+j);
        if (i != j) st.insert(c[i][j]);
      }
      if (st.size() <= 1)
        live[i] = 0;
    }
    bool ok = true;
    while (ok) {
      ok = 0;
      for (int i = 0; i < n; i++) {
        if (!live[i]) continue;
        set< int > st;
        for (int j = 0; j < n; j++) {
          if (!live[j] || j == i) continue;
          st.insert(c[i][j]);
        }
        if (st.size() <= 1) {
          ok = 1;
          live[i] = 0;
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
      if (live[i])
        ans++;
    for (int i = 0; i < n; i++) {
      if (!live[i]) continue;
      set< int > ed;
      for (int j = 0; j < n; j++) {
        if (!live[j]) continue;
        if (i == j) continue;
        ed.insert(c[i][j]);
      }
      assert(ed.size() > 1);
    }
    printf("%d\n", ans);
  }
  return 0;
}