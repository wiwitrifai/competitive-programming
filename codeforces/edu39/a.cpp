#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    ans += abs(x);
  }
  cout << ans << endl;
  return 0;
}