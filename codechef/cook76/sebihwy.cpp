#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int s, sg, fg, d, t;
    scanf("%d %d %d %d %d", &s, &sg, &fg, &d, &t); 
    int v = s * t + 36 * d * 5;
    sg *= t;
    fg *= t;
    if (abs(sg-v) == abs(fg-v))
      puts("DRAW");
    else if (abs(sg-v) < abs(fg-v))
      puts("SEBI");
    else
      puts("FATHER");
  }
  return 0;
}