#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 6;
char s[N];
int main() {
  scanf("%s", s);
  int a, b, c, n;
  a = b = c = 0;
  n = strlen(s);
  long long ans = 0;
  for(int i = 0; i<n; i++) {
    if(s[i] == '0') {
      a++;
      ans += b + c;
    }
    else if(s[i] == '1') {
      b++;
      ans += c;
    }
    else
      c++;
  }
  cout << ans << endl;
  return 0;
}