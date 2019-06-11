#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

int a[N], b[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d %d", a+i, b+i);
  int ans = n;
  while (ans >= 0) {
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      cnt += a[i] <= ans && ans <= b[i];
    }
    if (cnt == ans)
      break;
    --ans;
  }
  printf("%d\n", ans);
  return 0;
}
