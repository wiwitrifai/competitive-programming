#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    vector<int> e(n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &e[i]);
    }   
    sort(e.begin(), e.end());
    int ans = 0;
    for (int i = 0; i < n; ) {
      int j = 1;
      while (i+j <= n && e[i+j-1] > j) {
        j = e[i+j-1];
      }
      if (i+j <= n && e[i+j-1] <= j) {
        ++ans;
      }
      i += j;
    }
    printf("%d\n", ans);
  }
  return 0;
}
