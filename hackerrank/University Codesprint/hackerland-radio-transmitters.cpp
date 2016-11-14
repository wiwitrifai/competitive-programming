#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 6;

int x[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++)
    scanf("%d", x+i);
  sort(x, x+n);
  int ans = 0;
  for (int i = 0; i < n;) {
    ans++;
    int last = i;
    while (i+1 < n && x[i+1]-x[last] <= k) i++;
    int far = x[i]+k;
    while (i < n && x[i] <= far) i++;
  }
  printf("%d\n", ans);
  return 0;
}