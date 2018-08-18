#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int from[N], to[N];
vector<int> add[N], rem[N];

int a[N];

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 0; i <= q; ++i)
    from[i] = n, to[i] = -1;
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    from[a[i]] = min(from[a[i]], i);
    to[a[i]] = max(to[a[i]], i);
  }
  from[1] = 0;
  to[1] = n-1;
  if (from[q] > to[q]) {
    if (from[0] > to[0]) {
      puts("NO");
      return 0;
    }
    a[from[0]] = q;
    from[q] = to[q] = from[0];
  }
  for (int i = 1; i <= q; ++i) {
    if (from[i] > to[i]) continue;
    add[from[i]].push_back(i);
    rem[to[i]+1].push_back(i);
  }
  set<int> st;
  for (int i = 0; i < n; ++i) {
    for (int x : add[i])
      st.insert(x);
    for (int x : rem[i])
      st.erase(x);
    int ma = *st.rbegin();
    if (a[i] == 0)
      a[i] = ma;
    if (a[i] < ma) {
      puts("NO");
      return 0;
    }
  }
  printf("YES\n");
  for (int i = 0; i < n; ++i) {
    printf("%d%c", a[i], i == n-1 ? '\n' : ' ');
  }

  return 0;
}