#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n[3], a[3][N];
int main() {
  for(int i = 0; i<3; i++)
    scanf("%d", n+i);
  for(int i = 0; i<3; i++) {
    for(int j = 0; j<n[i]; j++) {
      scanf("%d", a[i]+j);
    }
    a[i][n[i]] = 0;
    for(int j = n[i]; j>0; j--)
      a[i][j-1] += a[i][j];
  }
  int id[3];
  for(int i = 0; i<3; i++)
    id[i] = 0;
  int s = -1;
  while(a[0][id[0]] != a[1][id[1]] || a[0][id[0]] != a[2][id[2]]) {
    if(a[0][id[0]] > a[1][id[1]])
      s = 0;
    else
      s = 1;
    if(a[s][id[s]] < a[2][id[2]])
      s = 2;
    id[s]++;
  }
  printf("%d\n", a[0][id[0]]);
  return 0;
}