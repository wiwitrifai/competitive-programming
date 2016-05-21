#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  long long ans = (1LL<<(n+1)) - 2;
  cout << ans << endl;

  return 0;
}