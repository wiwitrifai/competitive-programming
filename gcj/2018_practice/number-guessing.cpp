#include <bits/stdc++.h>

using namespace std;

int ask(int x) {
  cout << x << endl;
  string res;
  cin >> res;
  if (res == "CORRECT")
    return 0;
  else if (res == "TOO_SMALL")
    return -1;
  else if (res == "TOO_BIG")
    return 1;
  else
    assert(false);
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, n;
    cin >> a >> b >> n;
    bool ok = 0;
    while (a + 1 < b) {
      int m = (a + b + 1) >> 1;
      int res = ask(m);
      if (res == 0) {
        ok = 1;
        break;
      }
      else if (res < 0)
        a = m;
      else
        b = m-1;
    }
    if (!ok) {
      int res = ask(b);
      assert(res == 0);
    }
  }
  return 0;
}