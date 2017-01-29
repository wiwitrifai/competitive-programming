#include <bits/stdc++.h>

using namespace std;

int main() {
  long long n;
  cin >> n;
  if (n & 1) {
    bool ok = true;
    for (int i = 2; 1LL * i * i <= n; i++) {
      if ((n % i) == 0) {
        ok = false;
        break;
      }
    }
    if (ok)
      puts("1");
    else {
      n -= 2;
      ok  = true;
      for (int i = 2; 1LL * i * i <= n; i++) {
        if ((n % i) == 0) {
          ok = false;
          break;
        }
      }
      puts(ok ? "2" : "3");
    }
  }
  else if (n == 2)
    puts("1");
  else
    puts("2");
  return 0;
}