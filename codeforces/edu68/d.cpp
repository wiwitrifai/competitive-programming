#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    int ans = 0;
    if (k % 3) {
      ans = n % 3;
    }
    else {
      n %= k+1;
      if (n == k)
        ans = 3;
      else
        ans = n % 3;
    }
    puts(ans ? "Alice" : "Bob");
  }
  return 0;
}
