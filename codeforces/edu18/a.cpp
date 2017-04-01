#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;
int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i= 0; i< n; i++)
    scanf("%d", a+i);
  sort(a, a+n);
  int ans = 2e9 + 1, cnt = 0;
  for (int i = 0; i+1 < n; i++) {
    if (ans > a[i+1]-a[i])
      ans = a[i+1]-a[i], cnt = 1;
    else if (ans == a[i+1]-a[i])
      cnt++;
  }
  printf("%d %d\n", ans, cnt);
  return 0;
}