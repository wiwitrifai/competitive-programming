#include <bits/stdc++.h>

using namespace std;

int cnt[10005];

int a[5005], b[5005];

int main() {
  int n, p, q;
  scanf("%d %d %d", &n, &p, &q);
  for (int i = 0; i < p; i++) {
    scanf("%d", a+i);
  }
  for (int j = 0; j < q; j++)
    scanf("%d", b+j);
  for (int i = 0; i < p; i++) {
    for (int j = 0; j < q; j++) {
      int now = (a[i] + b[j]) % n;
      now = (n-now) % n;
      cnt[now]++;
    }
  }
  int ans = 1;
  cnt[n] = cnt[0];
  for (int i = 1; i <= n; i++) {
    if (cnt[i] < cnt[ans])
      ans = i;
  }
  printf("%d\n", ans);
  return 0;
}