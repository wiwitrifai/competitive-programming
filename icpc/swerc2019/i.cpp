#include <bits/stdc++.h>

using namespace std;

int main() {
  long long a, b, c;
  cin >> a >> b >> c;
  long long ans = ((a + 1) * (b + 1) / (c + 1)) - 1;
  cout << ans << endl;
  return 0;
}
