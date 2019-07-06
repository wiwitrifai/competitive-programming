// AC
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<int> g[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n-1; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  bool ok = 1;
  for (int i = 0; i < n; ++i)
    if ((int)g[i].size() == 2) {
      ok = 0;
    }
  puts(ok ? "YES" : "NO");
  return 0;
}
