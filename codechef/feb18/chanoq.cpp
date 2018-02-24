#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

bitset<N> bs[N];
vector<int> add[N], rem[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
      add[i].clear(), rem[i].clear();
    for (int i = 0; i < n; ++i) {
      int l, r;
      scanf("%d %d", &l, &r);
      --l;
      add[l].push_back(i);
      rem[r].push_back(i);
    }
    for (int i = 0; i < n; ++i) {
      if (i)
        bs[i] = bs[i-1];
      else
        bs[i].reset();
      for (int x : add[i])
        bs[i][x] = 1;
      for (int x : rem[i])
        bs[i][x] = 0;
    }
    int q;
    scanf("%d", &q);
    while (q--) {
      int m;
      scanf("%d", &m);
      bitset<N> ans;
      ans.reset();
      while (m--) {
        int x;
        scanf("%d", &x); --x;
        ans = ans ^ bs[x];
      }
      printf("%d\n", ans.count());
    }
  }

  return 0;
}