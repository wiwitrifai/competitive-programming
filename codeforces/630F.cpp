#include <bits/stdc++.h>

using namespace std;

long long C[800][20];

int main() {
  for(int i = 0; i<800; i++) {
    C[i][0] = 1;
    if(i < 20)
      C[i][i] = 1;
    for(int j = 1; j< min(20, i); j++)
      C[i][j] = C[i-1][j-1] + C[i-1][j];
  }
  int n;
  cin >> n;
  cout << (C[n][5] + C[n][6] + C[n][7]) << endl; 
  return 0;
}