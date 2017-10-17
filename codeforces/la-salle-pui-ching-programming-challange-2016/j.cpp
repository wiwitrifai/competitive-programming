#include <bits/stdc++.h>

using namespace std;

int main() {
  int h, w, a, b, p, q;
  cin >> h >> w >> a >> b >> p >> q;
  if (h < a || w < b) {
    puts("No");
    puts("No");
    return 0;
  }
  if ((h >= a + p && w >= max(b, q)) || (h >= max(a, p) && w >= b+q))
    puts("Yes");
  else
    puts("No");
  if (((h-a) < p * 2 || w < q) && ((w - b) < q * 2 || h < p))
    puts("Yes");
  else
    puts("No");
  return 0;
}