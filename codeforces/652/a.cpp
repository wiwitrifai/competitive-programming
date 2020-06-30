#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    puts(n & 3 ? "NO" : "YES");
  }
  return 0;
}
