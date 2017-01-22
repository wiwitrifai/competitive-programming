#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 6;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int c, d, l;
    scanf("%d %d %d", &c, &d, &l);
    if (l & 3)
      puts("no");
    else {
      int n = l/4;
      if (n <= c + d && n >= d + c - min(c, d * 2))
        puts("yes");
      else
        puts("no");
    }
  }

  return 0;
}