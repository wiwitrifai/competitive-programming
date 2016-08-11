#include <bits/stdc++.h>

using namespace std;

const int N = 102;

int a[N], p[N];

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= k; i++) {
    scanf("%d", a+i);
    p[a[i]] = i;
  }
  int now = n * m;
  int ans = 0;
  while(now--) {
    int x;
    scanf("%d", &x);
    int pos = p[x];
    for(int i = pos-1; i>0; i--) {
      int cur = a[i];
      p[cur]++;
      a[i+1] = cur;
    }
    p[x] = 1;
    a[1] = x;
    ans += pos;
  }
  printf("%d\n", ans);
  return 0;
}