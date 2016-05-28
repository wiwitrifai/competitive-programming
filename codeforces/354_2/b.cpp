#include <bits/stdc++.h>

using namespace std;

long long x[60][60], pw[60];

int main() {
  pw[0] = 1;
  for(int i = 1; i<20; i++)
    pw[i] = 2LL*pw[i-1];
  int n, t;
  scanf("%d%d", &n, &t);
  x[0][0] = t;
  int ans = 0;
  for(int i = 0; i<n; i++) {
    for(int j = 0; j<=i; j++) if(x[i][j] >= pw[i]) {
      ans++;
      int diff = x[i][j] - pw[i];
      x[i+1][j] += diff;
      x[i+1][j+1] += diff;
    }
  }
  cout << ans << endl;
  return 0;
}