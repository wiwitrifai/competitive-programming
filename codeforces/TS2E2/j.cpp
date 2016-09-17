#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  long long a = n/2, b = n - a;
  cout << b * (b - 1) / 2 * a + a * (a-1) * (a-2) / 6 << endl; 

  return 0;
}