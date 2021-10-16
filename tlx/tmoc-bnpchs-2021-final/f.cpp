#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; (1 << i) <= x; ++i) {
    if ((x & (1 << i)) == 0) continue;
    int len = (1 << i);
    for (int j = 0; j + len < n; ++j) {
      a[j] ^= a[j + len];
    }
  }
  for (int i = 0; i < n-x; ++i) {
    cout << a[i] << ((i+1 == n-x) ? '\n' : ' ');
  }
  return 0;
}
