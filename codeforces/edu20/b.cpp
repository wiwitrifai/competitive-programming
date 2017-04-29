#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 6;
int a[N], ans[N];

int main() {
  int n;
  scanf("%d", &n);
  int last = -N;
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
    if (a[i] == 0)
      last = i;
    ans[i] = i-last;
  }
  last = n + N;
  for (int i = n-1; i >= 0; i--) {
    if (a[i] == 0)
      last = i;
    ans[i] = min(ans[i], last-i);
  }
  for (int i = 0; i < n; i++)
    printf("%d ", ans[i]);
  printf("\n");
  return 0;
}