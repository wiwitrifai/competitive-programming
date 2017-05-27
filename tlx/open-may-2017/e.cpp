#include <bits/stdc++.h>

using namespace std;

const int N = 5050;

long long C[N][N];

int main() {
  for (int i = 0; i < N; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++)
      C[i][j] = C[i-1][j-1] + C[i-1][j];
  }
  for (int n = 1; n <= 15; n++) {
    long long cur = 0;
    for (int j = 0; j <= n; j += 5)
      cur += C[n][j];
    cerr << cur << " ";
  } 


  return 0; 
}