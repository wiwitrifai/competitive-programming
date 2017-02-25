#include <bits/stdc++.h>

using namespace std;

int x[6];

int main() {
  int n, p;
  scanf("%d %d", &n, &p);
  memset(x, 0, sizeof x);
  for (int i = 0; i < 3; i++) x[i] = i;
  n %= 6;
  for (int i = 1; i <= n; i++) {
    if (i&1)
      swap(x[0], x[1]);
    else
      swap(x[1], x[2]);
  }
  int ans = x[p];
  cout << ans << endl;
  return 0;
}