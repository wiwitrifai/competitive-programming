#include <bits/stdc++.h>

using namespace std;
const int n = 8;
int grundi[n][n];
bool a[n*n];

int main() {
  for(int i = 0; i<n; i++) {
    grundi[0][i] = 0;
  }
  for(int i = 1; i<n; i++) {
    for(int j = 1; j<n; j++) {
      memset(a, false, sizeof a);
      for(int k = 1; k<=j; k++) {
        a[grundi[i-1][k] ^ grundi[i][j-k]] = true;
      }
      for(int k = 0; k<n*n; k++)
        if(!a[k]) {
          grundi[i][j] = k;
          break;
        }
      printf("\t%d", grundi[i][j]);
    }
    printf("\n");
  }
  return 0;
}