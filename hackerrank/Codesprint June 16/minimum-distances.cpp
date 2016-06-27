#include <bits/stdc++.h>


using namespace std;

const int N = 1e5 + 5;

int n, last[N];

int main() {
  memset(last,-1, sizeof last);
  scanf("%d", &n);
  int ans = n;
  for(int i = 0; i<n; i++) {
    int x;
    scanf("%d", &x);
    if(last[x] >= 0)
      ans = min(ans, i-last[x]);
    last[x] = i;
  }
  if(ans == n) ans = -1;
  printf("%d\n", ans);
  return 0;
}