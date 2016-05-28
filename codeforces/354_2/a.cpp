#include <bits/stdc++.h>

using namespace std;

int n, a, b;

int main() {
  scanf("%d", &n);
  for(int i = 0; i<n; i++) {
    int x;
    scanf("%d", &x);
    if(x == 1)
      a = i;
    if(x == n)
      b = i;
  } 
  int ans = abs(a-b);
  ans = max(ans, max(a, n-1-a));
  ans = max(ans, max(b, n-1-b));
  cout << ans << endl;
  return 0;
}