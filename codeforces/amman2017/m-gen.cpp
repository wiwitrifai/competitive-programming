#include <bits/stdc++.h>

using namespace std;

int a[20];

int main() {
  srand(time(0));
  int t = 1000;
  printf("%d\n", t);
  while (t--) {
    int n = 18;
    printf("%d\n", n);
    a[0] = 0;
    a[1] = 1;
    for (int i = 2; i < n; i++)
      a[i] = i & 1;
    for (int i = 1; i < n; i++) {
      a[i] += a[i-1];
    }
    sort(a, a+n);
    for (int i = 0; i < n; i++)
      for (int j = i+1; j < n; j++)
        printf("%d ", a[j]-a[i]);
    printf("\n");
  }
  return 0;
}