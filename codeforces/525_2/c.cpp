#include <bits/stdc++.h>

using namespace std;

const int N = 2048;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  int x = 2e5;
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i), a[i] += x;
  printf("%d\n", n+1);
  printf("1 %d %d\n", n, x);
  for (int i = 0; i < n; ++i) {
    printf("2 %d %d\n", i+1, a[i] - (i+1));
  }
  return 0;
}