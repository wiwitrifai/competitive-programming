#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
vector<int> painters[N];

void solve() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<int> a(n), b(n), c(m);
  for (int i = 0; i < n; ++i)
    scanf("%d", &a[i]);
  for (int i = 0; i < n; ++i)
    scanf("%d", &b[i]);
  for (int i = 0; i <= n; ++i)
    painters[i].clear();
  for (int i = 0; i < m; ++i) {
    scanf("%d", &c[i]);
    painters[c[i]].push_back(i);
  }
  vector<int> ans(m, -1);
  for (int i = 0; i < n; ++i) {
    if (a[i] == b[i]) continue;
    if (painters[b[i]].empty()) {
      puts("NO");
      return;
    }
    ans[painters[b[i]].back()] = i+1;
    painters[b[i]].pop_back();
  }
  for (int i = 0; i < n; ++i) {
    while (!painters[b[i]].empty()) {
      ans[painters[b[i]].back()] = i+1;
      painters[b[i]].pop_back();
    }
  }
  if (ans[m-1] == -1) {
    puts("NO");
    return ;
  }
  puts("YES");
  for (int i = 0; i < m; ++i)
    printf("%d%c", ans[i] == -1 ? ans[m-1] : ans[i], i+1 == m ? '\n' : ' ');
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
