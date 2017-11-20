#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

int a[N], n, k;

int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  sort(a, a+n);
  int sum = 0;
  for (int i = 0; i < k; i++)
    sum += a[i];
  int ans = (sum + 99)/ 100;
  printf("%d\n", ans);

  return 0;
}