#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int p[N], s[N], n, m;
int a[N], b[N], c, u;
set < pair< int, int > > st;
vector< pair<int, int > > vs;

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", p+i);
    st.insert({p[i], i});
  } 
  for (int i = 0; i < m; i++) {
    scanf("%d", s+i);
    vs.push_back({s[i], i});
  }
  sort(vs.begin(), vs.end());
  u = 0;
  c = 0;
  for (int i = 0; i < m; i++) {
    int now = vs[i].first;
    int id = vs[i].second;
    a[id] = 0;
    int x = 0;
    while (now) {
      auto it = st.lower_bound({now, -1});
      if (it != st.end() && it->first == now) {
        b[it->second] = id+1;
        a[id] = x;
        st.erase(it);
        u += x;
        c++;
        break;
      }
      x++;
      if (now < 2)
        break;
      now = (now + 1) >> 1;
    }
  }
  printf("%d %d\n", c, u);
  for (int i = 0; i < m; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", b[i]);
  } 
  printf("\n");


  return 0;
}