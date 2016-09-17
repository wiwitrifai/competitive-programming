#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    if (m > n)
      swap(n, m);
    if (n == 1 || m == 1)
      puts("No");
    else {
      switch(n % 6) {
        case 0 :
          puts((m == 1) ? "No" : "Yes");
          break;
        case 1:
        case 5:
          puts((m % 6) ? "No" : "Yes");
          break;
        case 2:
        case 4:
          puts((m % 3) ? "No" : "Yes");
          break;
        case 3:
          puts((m & 1) ? "No" : "Yes");
          break;
        default:
          assert(false);
      }
    }
  }
  return 0;
}