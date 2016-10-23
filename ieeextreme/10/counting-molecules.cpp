/**
  IEEExtreme Programming Contest 10
  Problem : Counting Molecules
  Solver  : Luqman Arifin S
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  long long c, h, o;
  cin >> c >> h >> o;
  long long B = 2 * o - h;
  if (B % 4) {
    puts("Error");
    return 0;
  }
  B /= 4;
  long long A = 2 * o - 4 * c + h;
  if (A % 4) {
    puts("Error");
    return 0;
  }
  A /= 4;
  long long C = 4 * c - 2 * o + h;
  if (C % 24) {
    puts("Error");
    return 0;
  }
  C /= 24;
  printf("%lld %lld %lld\n", A, B, C);
  return 0;
  
}
