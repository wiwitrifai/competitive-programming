#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      int now = i * j + (n-i) * (m-j);
      if (now == k) {
        puts("Yes");
        return 0;
      }
    }
  } 
  puts("No");
  return 0;
}