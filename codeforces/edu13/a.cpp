#include <bits/stdc++.h>

using namespace std;

int main() {
  long long n, k, x;
  cin >> n >> k;
  x = n/k;
    x++;
  x *= k;
  cout << x << endl;

  return 0;
}