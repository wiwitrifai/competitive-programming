#include <bits/stdc++.h>

using namespace std;

int val[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main() {
  int a, b;
  cin >> a >> b;
  long long ans = 0;
  for (int i = a; i <= b; i++) {
    int x = i;
    ans += val[x % 10];
    x /= 10;
    while (x) {
      ans += val[x % 10];
      x /= 10;
    }
  }
  cout << ans << endl;
  return 0;
}