#include <bits/stdc++.h>

using namespace std;

void solve() {
  long long xa, ya, xb, yb;
  cin >> xa >> ya >> xb >> yb;
  long long dx = abs(xa - xb), dy = abs(ya - yb);
  if (dx > dy)
    swap(dx, dy);
  long long k = (dy - dx) / 2;
  dx += k * 2;
  while (dx + 2 < dy)
    dx += 2;
  while (dx > dy)
    dx -= 2;
  cout << dx + dy << "\n";
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
