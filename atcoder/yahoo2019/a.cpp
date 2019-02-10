#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  n = (n + 1) / 2;
  puts(k <= n ? "YES" : "NO");
  return 0;
}