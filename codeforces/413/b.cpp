#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int p[N], a[N], b[N];
bool used[N];
set< pair< int, int > > st[4];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", p+i);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i), st[a[i]].insert(make_pair(p[i], i));
  for (int i = 0; i < n; i++)
    scanf("%d", b+i), st[b[i]].insert(make_pair(p[i], i));
  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int c;
    scanf("%d", &c);
    int ans = -1;
    while (!st[c].empty()) {
      auto it = st[c].begin();
      if (!used[it->second]) {
        used[it->second] = 1;
        ans = it->first;
        st[c].erase(it);
        break;
      }
      else
        st[c].erase(it);
    }
    printf("%d ", ans);
  }
  printf("\n");
  return 0;
}