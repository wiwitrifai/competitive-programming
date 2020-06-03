#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, inf = 1e9 + 7;

int n, k;
int a[N];

int main() {
  scanf("%d%d", &n, &k);
  for(int i = 0; i<n; i++) {
    scanf("%d", a+i);
  }
  sort(a, a+n);
  int ans = 0; 
  if(k < 2)
    ans = 0;
  else
    ans = inf;
  k--;
  for(int i = k; i<n; i++) {
    ans = min(ans, a[i]-a[i-k]);
  }
  cout << ans << endl;
  return 0;
}