#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  long long n;
  cin >> n;
  long long ans = (n+10)/11;
  if (ans * 11 - 5 >= n)
    ans = ans * 2 - 1;
  else
    ans = 2 * ans;
  printf("%lld\n", ans);
 
  return 0;
}