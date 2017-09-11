#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];

int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    int ans = 1;
    for (int i = 1; i <= n; i++) {
      scanf("%d", a+i);
      if (a[i] < a[ans])
        ans = i;
    }
    printf("%d\n", ans);
  }
  return 0;
}