#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, t;
  scanf("%d %d", &n, &t);
  t -= n-1;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    t -= x;
  }
  puts(t == 0 ? "YES" : "NO");
  return 0;
}