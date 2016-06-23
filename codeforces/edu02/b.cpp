#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;
int n, m;
int a[N];


int main() {
  scanf("%d%d", &n, &m);
  for(int i = 0; i<n; i++) {
    scanf("%d", a+i);
  }
  sort(a, a+n);
  while(m--) {
    int b;
    scanf("%d", &b);
    int ans = upper_bound(a, a+n, b)-a;
    printf("%d ", ans);
  }
  printf("\n");
  return 0;
}