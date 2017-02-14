#include <bits/stdc++.h>

using namespace std;

int main() {
  long long a, b, k;
  cin >> k >> a >> b;
  long long pa = a/k, pb = b/k;
  a -= pa * k;
  b -= pb * k;
  if (pa == 0 && pb == 0)
    puts("-1");
  else if (pa == 0) {
    if (b != 0)
      puts("-1");
    else
      cout << pb << endl;
  }
  else if (pb == 0) {
    cout << ((a != 0) ? -1 : pa) << endl; 
  } 
  else
    cout << pa + pb << endl;
  return 0;
}