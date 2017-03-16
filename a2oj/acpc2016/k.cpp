#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    cout << n - (n+k)/(k+1) << endl;
  }
  return 0;
}