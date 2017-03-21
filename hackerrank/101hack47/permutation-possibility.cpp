#include <bits/stdc++.h>

using namespace std;

bool used[100005];

int main() {
  int n;
  scanf("%d", &n);
  bool ok = 1;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    if (used[x])
      ok = 0;
    used[x] = 1;
  }
  puts(ok ? "YES" : "NO");
  return 0;
}