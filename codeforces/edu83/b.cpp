#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
      scanf("%d", &a[i]);
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    for (int i = 0; i < n; ++i)
      printf("%d%c", a[i], i + 1 == n ? '\n' : ' ');
  }
  return 0;
}
