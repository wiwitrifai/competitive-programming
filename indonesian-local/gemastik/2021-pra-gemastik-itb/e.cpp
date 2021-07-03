#include <bits/stdc++.h>


using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  int ans = n;
  int mini = a[0], pos = 0;
  for (int i = 1; i < n; ++i) {
    if (a[i] < mini) {
      mini = a[i];
      pos = i;
      ans = n;
      continue;
    }
    else if (a[i] == mini) {
      ans = min(ans, i - pos);
      pos = i;
    }
  }
  printf("%d\n", ans);
  return 0;
}
