#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  int ans = 0;
  while(a > 0 && b > 0) {
    if(a == 1 && b == 1)
      break;
    if(a > b) {
      a -= 2;
      b++;
    }
    else {
      a++;
      b -= 2;
    }
    ans++;
  } 
  cout << ans << endl;
  return 0;
}
