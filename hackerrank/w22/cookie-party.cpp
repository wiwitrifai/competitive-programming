#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  cout << ((m+n-1)/n) * n - m << endl;

  return 0;
}