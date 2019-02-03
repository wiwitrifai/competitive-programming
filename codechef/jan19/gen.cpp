#include <bits/stdc++.h>

using namespace std;

int main() {
  srand(time(0));
  int t = 1;
  printf("%d\n", t);
  int n, m, q;
  n = m = q = 2e5;
  printf("%d %d\n", n, m);
  for (int i = 0; i < m; ++i) {
    int x, y;
    x = rand() % n;
    y = rand() % n;
    printf("%d %d\n", x+1, y+1);
  }
  vector<vector<int> > que;
  while (q > 0) {
    int k = min((rand() % q) + 1, n / 100);
    set<int> st;
    while (st.size() < 2 * k) {
      st.insert(rand() % n);
    }
    que.push_back(vector<int>());
    for (int u : st)
      que.back().push_back(u);
    q -= k;
  }
  printf("%d\n", (int)que.size());
  for (int i = 0; i < que.size(); ++i) {
    printf("%d", (int)que[i].size());
    for (int u : que[i])
      printf(" %d", u+1);
    printf("\n");
  }
  return 0;
}