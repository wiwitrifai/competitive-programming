#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  set<int> seats;
  for (int i = 1; i <= m; ++i)
    seats.insert(i);
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    int ans = a;
    if (!seats.count(a)) {
      ans = *seats.begin();
    }
    seats.erase(ans);
    printf("%d%c", ans, i+1 == n ? '\n' : ' ');
  }

  return 0;
}
