#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

char a[N], b[N];
int n;
int main() {
  scanf("%d", &n);
  scanf("%s", a);
  scanf("%s", b);
  sort(a, a+n);
  sort(b, b+n);
  int mi = 0, ma = 0;
  int j = 0;
  for (int i = 0; i < n; i++) {
    if (a[j] <= b[i])
      j++;
    else
      mi++;
  }
  j = 0;
  for (int i = 0; i < n; i++) {
    if (a[j] < b[i])
      ma++, j++;
  }
  printf("%d\n%d\n", mi, ma);

  return 0;
}