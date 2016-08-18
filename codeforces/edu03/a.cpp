#include <bits/stdc++.h>

using namespace std;

int n, m, a[1003];

int main() {
  scanf("%d%d", &n, &m);
  for(int i = 0; i<n; i++)
    scanf("%d", a+i);
  sort(a, a+n);
  int ans = 0;
  for(int i = n-1; i>=0; i--) {
    if(m <= 0)
      break;
    ans++;
    m -= a[i];
  }
  printf("%d\n", ans);
  return 0;
}