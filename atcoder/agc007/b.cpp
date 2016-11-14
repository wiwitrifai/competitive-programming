#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int sum[N];
int a[N], b[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    sum[x-1] = i;
  }
  a[0] = b[0] = 1;
  for (int i = 1; i < n; i++) {
    int c = sum[i] - sum[i-1];
    a[i] = a[i-1] + 1;
    b[i] = b[i-1] - 1;
    if (c > 0)
      a[i] += c;
    else
      b[i] += c;
  }
  int ma = -b[n-1] + 1;
  for (int i = 0; i < n; i++)
    b[i] += ma;
  for (int i = 0; i < n; i++)
    printf("%d ", a[i]);
  printf("\n");
  for (int i = 0; i < n; i++)
    printf("%d ", b[i]);
  printf("\n");
  return 0;
}