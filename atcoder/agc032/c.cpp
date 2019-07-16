#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int deg[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    ++deg[a];
    ++deg[b];
  }
  bool ok = 1;
  int dual = 0, triple = 0;
  for (int i = 1; i <= n; ++i) {
    ok &= ((deg[i] & 1) == 0);
    if (deg[i] == 4)
      ++dual;
    else if (deg[i] >= 6)
      ++triple;
  }
  // cerr << ok << " " << 
  if (!ok) {
    puts("No");
  }
  else if (triple) {
    puts("Yes");
  }
  else {
    puts(dual > 1 ? "Yes" : "No");
  }
  return 0;
}