#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    string str;
    cin >> str;
    cout << "Case #" << i << ": ";
    if (str == "semangat") {
      cout << "\\(^_^)/";
    } else if (str == "sebel") {
      cout << ">.<\"";
    } else {
      cout << "(' ')?";
    }
    cout << endl;
  }

  return 0;
}