#include <bits/stdc++.h>

using namespace std;

int main() {
  long long ans = 1, a, b;
  cin >> a >> b;
  if (b - a > 100) {
    puts("0");
    return 0;
  }
  for (long long c = a+1; c <= b; c++)
    ans = (ans * c) % 10;
  cout << ans << endl;
  return 0;
}