#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, a;
  int ans = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a);
    ans += a & 1;
  } 
  puts(ans & 1 ? "NO" : "YES");
  return 0;
}