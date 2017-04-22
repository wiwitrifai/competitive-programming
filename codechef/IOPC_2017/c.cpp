#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, inf = 1e8 + 7;

int a[N];


int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", a+i);
    }
    sort(a, a+n);
    for (int i = 0; i < n; i++)
      ans = max(ans, a[i] % a[n-1]);
    printf("%d\n", ans);
  }
  return 0;
}