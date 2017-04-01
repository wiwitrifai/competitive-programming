#include <bits/stdc++.h>

using namespace std;
int gcd(int a, int b) {
  return a ? gcd(b % a, a) : b;
}

int main() {
  long long cnt = 0;
  for (int i = 1; i <= 500; i++) {
    for (int j = i; j <= 500; j++) {
      if (gcd(i, j)) {
        
      }
    }
  }
  cout << cnt << endl;
  return 0;
}