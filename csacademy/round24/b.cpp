#include <bits/stdc++.h>

using namespace std;

int main() {
  int k;
  scanf("%d", &k);
  long long now = 0;
  while (k--) {
    now++;
    while (1) {
      bool ok = 1;
      int last = 0;
      long long cur = now;
      while (cur) {
        if (last && (cur & 1)) {
          ok = 0;
          break;
        }
        last = cur & 1;
        cur >>= 1;
      }
      if (ok)
        break;
      now++;
    }
  }
  cout << now << endl;
  return 0;
}