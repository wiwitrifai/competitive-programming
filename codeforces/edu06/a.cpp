#include <bits/stdc++.h>

using namespace std;

int main() {
  long long a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << max(abs(a-c), abs(b-d)) << endl;
  return 0;
}