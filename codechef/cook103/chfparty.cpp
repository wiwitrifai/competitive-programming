#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int a[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
      scanf("%d", a+i);
    sort(a, a+n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (ans < a[i])
        continue;
      ++ans;
    }
    printf("%d\n", ans);
  }
  return 0;
}