// can you hack wifi? :p
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  while (n--) {
    int x;
    scanf("%d", &x);
    bool ok = 0;
    for (int i = 0; i <= x; i += 3) {
      if ((x-i) % 7) continue;
      ok = 1;
    }
    puts(ok ? "YES" : "NO");
  }

  return 0;
}