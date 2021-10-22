#include <bits/stdc++.h>


using namespace std;

int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int a, b, c;
    cin >> a >> b >> c;
    cout << ((a == 7) || (b == 7) || (c == 7) ? "YES" : "NO") << endl;
  }
  return 0;
}
