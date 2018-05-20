#include <bits/stdc++.h>

using namespace std;

set<pair<int, int> > st;
const int N = 105;

int p[N];

int main() {
  int t;
  scanf("%d", &t);
  for (int tc = 1; tc <= t; ++tc) {
    printf("Case #%d:", tc);
    int n;
    scanf("%d", &n);
    st.clear();
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      scanf("%d", p+i);
      if (p[i] > 0)
        st.insert(make_pair(-p[i], i));
      sum += p[i];
    }
    while (!st.empty()) {
      auto it = st.begin();
      int v = it->second;
      st.erase(it);
      if (p[v] * 2 == sum) {
        it = st.begin();
        int u = it->second;
        st.erase(it);
        printf(" %c%c", v + 'A', u + 'A');
        --p[u];
        --p[v];
        if (p[u] > 0)
          st.insert(make_pair(-p[u], u));
        if (p[v] > 0)
          st.insert(make_pair(-p[v], v));
        sum -= 2;
      }
      else {
        printf(" %c", v + 'A');
        if (p[v] > 0)
          st.insert(make_pair(-p[v], v));
        --p[v];
        --sum;
      }
    }
    printf("\n");
  }
  return 0;
}