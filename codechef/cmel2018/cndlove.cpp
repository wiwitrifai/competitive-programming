#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      int x;
      scanf("%d", &x);
      sum += x;
    }
    puts(sum & 1 ? "YES" : "NO");
  }
  return 0;
}