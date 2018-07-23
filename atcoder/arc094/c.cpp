#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  int ans = 0;
  while (a != b || b != c) {
    if (b < a) swap(a, b);
    if (c < a) swap(a, c);
    if (c < b) swap(b, c);
    int d = c - a;
    if (d >= 2)
      a += 2;
    else {
      ++a;
      ++b;
    }
    ++ans;
  } 
  printf("%d\n", ans);
  return 0;
}