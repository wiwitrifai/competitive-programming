#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
      int f;
      scanf("%*s %d", &f);
      mp[f]++;
    }
    int ans = 0, big = -1;
    for (auto it : mp) {
      if (it.second > big) {
        big = it.second;
        ans = it.first;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}