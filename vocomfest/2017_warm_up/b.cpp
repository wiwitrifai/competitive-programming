#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  for (int tc = 1; tc <= t; tc++) {
    int a, b, c;
    cin >> a >> b >> c;
    printf("Case #%d: %d\n", tc, (a+b) % c);
  }
  return 0;
}