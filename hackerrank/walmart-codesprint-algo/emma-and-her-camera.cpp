#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, x;
  cin >> n >> x;
  cout << abs(x - ((1<<n)-1)) << endl;
  return 0;
}