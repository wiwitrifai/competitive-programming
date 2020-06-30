#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  if (k == 2) {
    puts("-1");
    return 0;
  }
  vector<int> ans(n);
  for (int i = 1, j = 0; j < n; j += 2, ++i) {
    ans[j] = i;
  }
  for (int i = n, j = 1; j < n; j += 2, --i) {
    ans[j] = i;
  }
  for (int i = 0; i < n; ++i) {
    printf("%d%c", ans[i], i+1 == n ? '\n' : ' ');
  }
  return 0;
}
