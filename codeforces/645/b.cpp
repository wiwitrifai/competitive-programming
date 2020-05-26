#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
    }
    int ans = 1;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
      if (a[i] <= i+1) {
        ans = i+2;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
