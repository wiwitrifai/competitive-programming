#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;
int a[N], b[N], id[N];
int bef[N];
bool cmpA(int x, int y) {
  return (a[x] < a[y]);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
      scanf("%d", &x), a[x-1] = i;
    for (int i = 0; i < n; i++)
      scanf("%d", &x), b[x-1] = i, id[i] = i;
    sort(id, id+n, cmpA);
    set< pair< int, int > > st;
    memset(bef, -1, sizeof bef);
    for (int i = 0; i < n; i++) {
      int now = id[i];
      auto it = st.lower_bound(make_pair(-b[now], now));
      if (it != st.end()) {
        bef[now] = it->second;
        st.erase(it);
      }
      st.insert(make_pair(-b[now], now));
    }
    printf("%d\n", st.size());
    for (auto it : st) {
      stack < int > stak;
      int now = it.second;
      while (now >= 0) {
        stak.push(now);
        now = bef[now];
      }
      printf("%d", stak.size());
      while (!stak.empty()) {
        printf(" %d", stak.top() + 1);
        stak.pop();
      }
      printf("\n");
    }
  }
  return 0;
}