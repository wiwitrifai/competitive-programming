#include <bits/stdc++.h>

using namespace std;

int main() {
  string a, b;
  cin >> a >> b;
  auto convert = [&](string s) {
    vector<int> res;
    for (int i = 0; i < (int)s.size();) {
      if (s[i] == 'o') {
        res.push_back(1);
        i += 3;
      } else {
        res.push_back(0);
        i += 4;
      }
    }
    return res;
  };
  auto va = convert(a);
  auto vb = convert(b);
  if (va.size() != vb.size()) {
    puts((va.size() > vb.size()) ? ">" : "<");
  } else {
    puts(va > vb ? ">" : (va < vb ? "<" : "="));
  }
  return 0;
}
