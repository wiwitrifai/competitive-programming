#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  int ans = n, sum = 0;
  for(int i = 0; i<n; i++) {
    int x;
    scanf("%d", &x);
    sum += x;
  }
  sum -= 2*n;
  sum = max(sum, 0);
  ans += (sum + 1)/2;
  cout << ans << endl;
  return 0;
}