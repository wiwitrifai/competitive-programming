#include <bits/stdc++.h>

using namespace std;

int main() {
  long long n, m;
  cin >> n >> m;
  int a = n/5, b = m/5;
  long long ans = 1LL*a*b;
  for(int i = 1; i<5; i++) {
    a = (n+i)/5;
    b = (m+5-i)/5;
    ans += 1LL*a*b;
  }
  cout << ans << endl;
  return 0;
}