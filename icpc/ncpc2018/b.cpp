#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> s;
    if (s == "mumble")
      continue;
    int cur = stoi(s);
    cerr << s << endl;
    if (cur != i) {
      cout << "something is fishy" << endl;
      return 0;
    }
  }
  cout << "makes sense" << endl;
  return 0;
}