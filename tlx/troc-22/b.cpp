#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  string s(n, 'a');
  for (int i = 0; i < n; ++i) {
    s[i] += i % 3;
  }
  cout << s << endl;
  return 0;
}
