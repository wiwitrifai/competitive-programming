#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

int deg[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, x;
    scanf("%d %d", &n, &x);
    --x;
    fill(deg, deg+n, 0);
    for (int i = 0; i < n-1; ++i) {
      int u, v;
      scanf("%d %d", &u, &v);
      --u, --v;
      ++deg[u];
      ++deg[v];
    }
    if (deg[x] <= 1) {
      puts("Ayush");
      continue;
    }
    puts((n & 1) ? "Ashish" : "Ayush");
  }
  return 0;
}
