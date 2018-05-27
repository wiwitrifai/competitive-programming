#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int d[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v); --u, --v;
    ++d[u], ++d[v];
  }
  int root = 0;
  for (int i = 0; i < n; ++i) {
    if (d[i] > d[root]) root = i;
  }
  bool ok = 1;
  for (int i = 0; i < n; ++i) {
    if (i == root) continue;
    if (d[i] > 2) {
      ok = 0;
      break;
    }
  }
  if (ok) {
    puts("Yes");
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
      if (i == root) continue;
      if (d[i] == 1) {
        ans.push_back(i);
      }
    }
    printf("%d\n", (int)ans.size());
    for (int u : ans)
      printf("%d %d\n", root+1, u+1);
  }
  else {
    puts("No");
  }
  return 0;
}