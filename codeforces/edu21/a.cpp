#include <bits/stdc++.h>

using namespace std;

int main() {
  long long n;
  cin >> n;
  long long val = 1;
  while (val * 10 <= n)
    val *= 10;
  long long ans = 0;
  while (ans <= n)
    ans += val;
  cout << ans - n << endl;
  return 0;
}