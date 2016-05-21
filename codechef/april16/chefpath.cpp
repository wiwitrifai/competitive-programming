#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    long long n, m;
    scanf("%lld%lld", &n, &m);
    if(n > m)
      swap(n, m);
    if(((n & 1) == 0) || ((m & 1) == 0)) {
      if(n == 1)
        puts(m == 2 ? "Yes" : "No");
      else
        puts("Yes");
    }
    else
      puts("No");
  }
  
  return 0;
}