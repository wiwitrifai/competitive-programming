#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &a[i]);
  if (n == 2) {
    puts(a[0] != a[1] ? "YES" : "NO");
    return 0;
  }
  int all = 0;
  for (int i = 0; i < n; ++i)
    all |= a[i];
  if (all == 0) {
    puts("NO");
    return 0;
  }
  puts("YES");
  return 0;
}
