#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
long long a[N];

int main() {
  a[0] = a[1] = a[2] = 1;
  for(int i = 3; i<50; i++) {
    a[i] = 0;
    for(int j = 1; j<i; j++)
      a[i] += a[j] * a[i-j];
    a[i] = (a[i] * i)/2;
    cout << i << " " << a[i] << endl;
  }
  

  return 0;
}