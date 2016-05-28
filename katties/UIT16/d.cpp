#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int t[N];
int main() {
  int n, k, l, ans;
  scanf("%d%d", &n, &k);
  ans = l = 0;
  for(int i = 0; i<n; i++) {
    scanf("%d", t+i);
    while(l < i && t[l] + 1000 <= t[i]) l++;
    ans = max(ans, i-l+1);
  }
  printf("%d\n", (ans + k-1)/k);
  return 0;
}