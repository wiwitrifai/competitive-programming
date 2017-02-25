#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6, inf = 1e9 + 7;

int a[N], b[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", a+i, b+i);
  }
  int now = a[0];
  int ans = inf, cnt = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == now)
      now = b[i];
    else if (now == b[i])
      now = a[i], cnt++;
    else {
      now = -1;
      break;
    }
  }
  if (now != -1)
    ans = min(ans, cnt);
  now = b[0];
  cnt = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == now)
      now = b[i];
    else if (now == b[i])
      now = a[i], cnt++;
    else {
      now = -1;
      break;
    } 
  }
  if (now != -1)
    ans = min(ans, cnt);
  if (ans >= inf)
    ans = -1;
  printf("%d\n", ans);
  return 0 ;
}