#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k, l;
  scanf("%d %d %d", &n, &k, &l);
  --n;
  if (n <= l && n <= k) {
    puts("A");
    return 0;
  }
  if (k >= l) {
    puts("A");
    return 0;
  }
  puts("B");
  return 0;
}
