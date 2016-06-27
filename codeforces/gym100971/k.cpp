#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

char s[N];
int main() {
  scanf("%s", s);
  int n = strlen(s);
  int ans = -1;
  int l = 0, r = n-1;
  while(l < r && s[l] == s[r]) l++, r--;
  if(l>= r) {
    ans = (n+1)/2;
  }
  else {
    int ll = l+1, rr = r;
    while(ll < rr && s[ll] == s[rr]) ll++, rr--;
    if(ll >= rr)
      ans = l+1;
    ll = l, rr = r-1;
    while(ll < rr && s[ll] == s[rr]) ll++, rr--;
    if(ll >= rr)
      ans = r+1;
  }
  if(ans == -1)
    puts("NO");
  else {
    puts("YES");
    printf("%d\n", ans);
  }
  return 0;
}