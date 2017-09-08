#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;

int a[N], n, b[N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
  }
  for (int i = n-1; i >= 0; i--) {
    b[i] = b[i+1] + a[i];
  }
  int cnt = 0;
  int ans = b[0];
  for (int i = 0; i < n; i++) {
    cnt += a[i] == 0;
    ans = max(ans, cnt + b[i+1]);
  }
  ans = max(ans, cnt);
  printf("%d\n", ans);
  return 0;
}