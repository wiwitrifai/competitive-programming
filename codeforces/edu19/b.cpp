#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 6;

int a[N], n;

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", a+i);
  int cnt = 0, sum = 0;
  int posval = 0, negval = 0;
  for (int i = 0;i < n; i++) {
    if (a[i] > 0) {
      cnt++;
      sum += a[i];
    }
    if (a[i] & 1) {
      if (a[i] < 0) {
        if (negval == 0 || negval < a[i])
          negval = a[i];
      }
      else {
        if (posval == 0 || posval > a[i])
          posval = a[i];
      }
    }
  }
  if (sum & 1)
    printf("%d\n", sum);
  else {
    int ans = -1e9 - 7;
    if (posval > 0)
      ans = max(ans, sum-posval);
    if (negval < 0)
      ans = max(ans, sum+negval);
    printf("%d\n", ans);
  }
  return 0;
}