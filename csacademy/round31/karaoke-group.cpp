#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int n, m;
bitset< N > a[N];

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    for (int j = 0; j < x; j++) {
      int s;
      scanf("%d", &s);
      a[i][s] = 1; 
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = i+1; j < n; j++)
      ans = max(ans, (int)(a[i] & a[j]).count());
  printf("%d\n", ans);
  return 0;
}