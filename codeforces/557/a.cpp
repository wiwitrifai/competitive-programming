#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int ada[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  set<pair<int, int> > st;
  for (int i = 0; i < k; ++i) {
    int a;
    scanf("%d", &a);
    if (a-1 >= 1 && ada[a-1])
      st.insert(make_pair(a-1, a));
    if (a+1 <= n && ada[a+1])
      st.insert(make_pair(a+1, a));
    ada[a] = 1;
  }
  int ans = 2 * (n - 1) - (int)st.size();
  for (int i = 1; i <= n; ++i)
    ans += !ada[i];
  printf("%d\n", ans);
  return 0;
}
