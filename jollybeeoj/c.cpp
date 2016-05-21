#include <bits/stdc++.h>

using namespace std;

string s;

int main() {

  // a[0] = 0;
  // for(int i = 1; i<=n; i++) {
  //   int x = a[i/2] ^ a[(i+1)/2], y = a[i-1];
  //   a[i] = 0;
  //   if(x > y)
  //     swap(x, y);
  //   if(a[i] == x)
  //     a[i]++;
  //   if(a[i] == y)
  //     a[i]++;
  //   cout << i << " " << a[i] << endl;
  // }
  cin >> s;
  if(s.size() == 1 && s[0] < '3')
      puts("First");
    else {
      int x = s.back()-'0';
      puts((x & 1) == 0 ? "First" : "Second");
    }
  return 0;
}