#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int t[N], n, m, id[N];

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", t+i);
    t[i] -= i;
    id[i] = i;
    t[i] = max(t[i], 0);
  }
  int z = m-1-n;
  sort(id+1, id+n+1, [](int l, int r) { return t[l] < t[r]; });
  int k = 1;
  int ans = 0, cur = 0;
  for (int i = n; i > 0; i--, z++) {
    while (k <= n && t[id[k]] <= z) cur += id[k] <= i, k++;
    ans = max(ans, cur);
    if (t[i] <= z)
      cur--;
  }
  printf("%d\n", ans);
  return 0;
}