#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[12];

int main() {

  memset(a, 0, sizeof a);
  scanf("%d%d", &n, &m);
  for(int i = 0; i<n; i++) {
    int x;
    scanf("%d", &x);
    a[x]++;
  }
  int ans = 0;
  for(int i = 1; i<=m; i++) {
    n -= a[i];
    ans += n * a[i];
  }
  printf("%d\n", ans);
  return 0;
}