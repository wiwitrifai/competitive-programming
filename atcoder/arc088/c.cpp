#include <bits/stdc++.h>

using namespace std;

int main() {
  long long x, y;
  cin >> x >> y;
  int ans = 0;
  while (x <= y) x <<= 1, ans++;
  cout << ans << endl;
  return 0;
}