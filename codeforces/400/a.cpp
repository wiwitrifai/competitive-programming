#include <bits/stdc++.h>

using namespace std;

int main() {
  string a, b;
  cin >> a >> b;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string c, d;
    cout << a << " " << b << "\n";
    cin >> c >> d;
    if (a == c) {
      a = d;
    }
    else
      b = d;
  }
  cout << a << " " << b << "\n";
  return 0;
}