#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, mod = 1e9 + 7;

int a, b, n, v[N], ans;

int main() {
  ans = 0;
  scanf("%d %d %d", &a, &b, &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", v+i);
    if (a > b) {
      if (a >= v[i])
        a -= v[i];
      else
        ans++;
    }
    else {
      if (b >= v[i])
        b -= v[i];
      else
        ans++;
    }
  }
  printf("%d\n", ans);

  return 0;
}