#include <bits/stdc++.h>

using namespace std;

int main() {
  long long a, b, c, k;
  cin >> a >> b >> c >> k;
  long long ans = a - b;
  if (k & 1)
    ans = -ans;
  cout << ans << endl;
  return 0;
}