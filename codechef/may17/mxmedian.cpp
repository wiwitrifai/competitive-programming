#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], b[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 2 * n; i++)
      scanf("%d", a+i);
    sort(a, a+2*n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      b[i * 2] = a[i], b[i * 2 + 1] = a[i+n];
      if (i == n/2)
        ans = max(b[i*2], b[i*2+1]);
    }

    printf("%d\n", ans);
    for (int i = 0; i < 2 * n; i++)
      printf("%d ", b[i]);
    printf("\n");
  }
  return 0;
}