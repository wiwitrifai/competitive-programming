#include <bits/stdc++.h>

using namespace std;

int a[100][140], grund[100];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for(int i = 0; i<n; i++)
    a[i][i] = 1;

  for(int j = 1; j<=n; j++) {
    while(a[j][grund[j]]) grund[j]++;
    printf("% 3d ", grund[j]);
  }
  printf("\n");
  for(int i = 1; i<k; i++) {
    for(int j = n; j>=1; j--) {
      for(int x = 0; x < 128; x++) if(a[j][x]) {
        for(int y = j+1; y<=n; y++)
          a[y][x ^ (y-j)] = 1;
      }
    }
    for(int j = 1; j<=n; j++) {
      while(a[j][grund[j]]) grund[j]++;
      printf("% 3d ", grund[j]);
    }
    printf("\n");
  }
  


  return 0;
}