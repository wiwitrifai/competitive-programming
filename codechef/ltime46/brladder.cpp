#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int a, b;
    scanf("%d %d", &a, &b);
    if (a > b) swap(a, b);
    if (((a & 1) && b == a+1) || (b == a + 2))
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}