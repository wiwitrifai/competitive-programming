#include <bits/stdc++.h>

using namespace std;

int main() {
  int b, k;
  scanf("%d %d", &b, &k);
  int ans = 0;
  b &= 1;
  for (int i = k-1; i >= 0; --i) {
    int pw = i ? b : 1;
    int a;
    scanf("%d", &a);
    a &= 1;
    a *= pw;
    ans += a;
  }
  puts(ans&1 ? "odd" : "even");
  return 0;
}