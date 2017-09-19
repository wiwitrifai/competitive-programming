#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int l[N], r[N];
bool vis[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", l+i, r+i);
  }
  int last = 0;
  for (int i = 1; i <= n; i++) {
    if (l[i] == 0) {
      r[last] = i;
      l[i] = last;
      int v = i;
      while (r[v] != 0)
        v = r[v];
      last = v;
    }
  }
  for (int i = 1; i <= n; i++)
    printf("%d %d\n", l[i], r[i]);
  return 0;
}