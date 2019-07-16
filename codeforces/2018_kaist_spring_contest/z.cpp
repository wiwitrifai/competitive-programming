#include <bits/stdc++.h>

using namespace std;

const int N = 5050;

int a[N];

bool zigzag(int x, int y, int z) {
  if (x <= y && y <= z)
    return false;
  if (x >= y && y >= z)
    return false;
  return true;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
  }
  int ans = 2;
  for (int i = 0; i+1 < n; ++i) {
    if (a[i] == a[i+1]) continue;
    ans = max(ans, 2);
    for (int j = i+2; j < n; ++j) {
      if (!zigzag(a[j-2], a[j-1], a[j])) break;
      ans = max(ans, j-i+1);
    }
  }
  printf("%d\n", ans);
  return 0;
}
