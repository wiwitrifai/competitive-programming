#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
      scanf("%d", a+i);
    sort(a, a+n);
    int ans = 1;
    for (int i = 0, j = 0; i < n; i++) {
      while (a[i]-a[j] > m) j++;
      ans = max(ans, i-j+1);
    }
    printf("%d\n", ans);
  }
  return 0;
}