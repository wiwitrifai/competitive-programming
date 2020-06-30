#include <bits/stdc++.h>

using namespace std;

const int A = 1e8;

int solve() {
  int m, a, b;
  scanf("%d %d %d", &m, &a, &b);
  if ((b - a) % 3) {
    puts("Yes");
    return 0;
  }
  puts((abs(b - a))/3 <= m ? "No" : "Yes");
  return 0;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
