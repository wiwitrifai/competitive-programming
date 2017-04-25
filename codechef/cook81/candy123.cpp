#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int a, b;
    scanf("%d %d", &a, &b);
    bool ans = 0;
    for (int i = 1; ; i++) {
      if (i & 1) {
        if (a < i) {
          ans = 1;
          break;
        }
        a -= i;
      }
      else {
        if (b < i) {
          ans = 0;
          break;
        }
        b -= i;
      }
    }
    puts(ans ? "Bob" : "Limak");
  }
  return 0;
}