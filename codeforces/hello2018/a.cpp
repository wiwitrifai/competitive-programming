#include <bits/stdc++.h>

using namespace std;

int main() {
  long long n, m;
  cin >> n >> m;
  if (n > 30)
    cout << m << endl;
  else {
    cout << m % (1LL << n) << endl;
  }
  return 0;
}