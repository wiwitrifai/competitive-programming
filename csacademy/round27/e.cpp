#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, mod = 1e9 + 7;

int a[N], n;
int ans[N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
    int r = i + i, len = a[i];
    if (len & 1) {
      int c = r-len+1;
      ans[c] = max(ans[c], r-c);
    }
    else {
      int c = r-len+1;
      ans[c] = max(ans[c], r-c);
    }
  }
  int x = 0;
  for (int i = 0; i <= 2 * n; i++) {
    if (ans[x]+x >= i) {
      ans[i] = max(ans[i], min(ans[x-(i-x)], ans[x]+x-i));
    }
    if (ans[i]+i > ans[x]+x)
      x = i;
  }
  for (int i = 0; i < n; i++)
    printf("%d ", (ans[i * 2]/2) * 2 + 1);
  printf("\n");
  return 0;
}