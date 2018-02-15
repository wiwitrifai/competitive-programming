#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int main() {
  string s;
  cin >> s;
  string r = s;
  reverse(r.begin(), r.end());
  cout << s + r << endl;
  return 0;
}