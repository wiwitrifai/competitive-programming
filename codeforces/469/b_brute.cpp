#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    a[i * 2] = i+1;
  }
  for (int i = 2 * n, j = i-1; i >= 0; --i) {
    if (a[i] == 0) continue;
    j = min(j, i-1);
    while (j >= 0 && a[j] > 0) --j;
    if (j >= 0) 
      a[j] = a[i], a[i] = 0;
    else
      break;
  }
  for (int i = 0; i < n; ++i)
    printf("%d ", a[i]);
  printf("\n");
  return 0;
}