#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, p, b, q;
  cin >> a >> p >> b >> q;
  int ans = 0;
  int win = (p * a + 99)/100;
  for (int i = 0; i <= b-a; i++) {
    int qq = (win + i) * 100 / b;
    if (qq <= q) {
      ans = i;
    }
  }
  cout << ans << endl;
  return 0;
}