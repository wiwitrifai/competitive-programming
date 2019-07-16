#include <bits/stdc++.h>

using namespace std;

int main() {
  long long x, y, z;
  cin >> x >> y >> z;
  long long cnt = (x + y) / z, low = x / z + y / z;
  if (low == cnt) {
    cout << low << " 0" << endl;
    return 0;
  }
  long long trans = z;
  long long needx = (z - (x%z)) % z, needy = (z - (y % z)) % z;
  if (needx <= y) {
    trans = min(trans, needx);
  }
  if (needy <= x) {
    trans = min(trans, needy);
  }
  cout << cnt << " " << trans << endl;
  return 0;
}
