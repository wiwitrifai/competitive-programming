#include <bits/stdc++.h>

using namespace std;

int b[1 << 4];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    int c = 0;
    for (int j = 0; j < k; j++) {
      c <<= 1;
      int x;
      scanf("%d", &x);
      c |= x; 
    }
    b[c]++;
  }
  bool ans = 0;
  if (b[0])
    ans = 1;
  for (int i = 0; i < (1 << k); i++) {
    if (b[i] == 0) continue;
    for (int j = i+1; j < (1 << k); j++) {
      if (b[j] == 0) continue;
      ans |= (i & j) == 0;
    }
  }
  puts(ans ? "YES" : "NO");
  return 0;
}