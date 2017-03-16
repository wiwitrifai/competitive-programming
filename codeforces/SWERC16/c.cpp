#include <bits/stdc++.h>

using namespace std;

int main() {
  int d, R, T;
  scanf("%d %d %d", &d, &R, &T);
  int x = (R + T + d - 2) / 2;
  cout << R - (5 + x) << endl; 
  return 0;
}