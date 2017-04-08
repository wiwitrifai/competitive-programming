#include <bits/stdc++.h>

using namespace std;

int main() {
  long long a, b, c, n, m;
  cin >> a >> b >> c >> n >> m;
  long long ans = a + b + c;
  if (n < a + c)
    ans = min(ans, n);
  if (m < b + c)
    ans = min(ans, m);
  cout << ans << endl;
}