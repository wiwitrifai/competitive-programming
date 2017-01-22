#include <bits/stdc++.h>

using namespace std;

const int N = 1000;
int x[N][N];

int main() {
  x[0][1] = 1;
  for (int i = 1; i < 129; i++) {
    cout << x[i][0];
    for (int j = 1; j < 129; j++)
      cout << (x[i][j] = x[i-1][j] ^ x[i][j-1]);
    cout << endl;
  }


  return 0;
}