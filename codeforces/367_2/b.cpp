#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int x[N];

int main() {
  int n, q, m;
  scanf("%d", &n);
  for(int i = 0; i<n; i++) {
    scanf("%d", x+i);
  }
  sort(x, x+n);
  scanf("%d", &q);
  while(q--) {
    scanf("%d", &m);
    int ans = upper_bound(x, x+n, m) - x;
    printf("%d\n", ans);
  }

  return 0;
}