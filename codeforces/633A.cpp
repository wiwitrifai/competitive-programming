#include <bits/stdc++.h>

using namespace std;

int main() {
  long long a, b, c;
  cin >> a >> b >> c;
  long long ans = 0;
  for(int i = 0; i<=c; i += a) {
      if((c-i) % b == 0) {
        puts("Yes");
        return 0;
      }
  }
  puts("No");
 
  return 0;
}