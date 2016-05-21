#include <bits/stdc++.h>

using namespace std;

int n, k;
int a[10][10];

int main() {
  scanf("%d%d", &n, &k);
  if(n > 6) {
    puts("YES");
    return 0;
  }
  memset(a, 0, sizeof a);
  for(int i = 0; i<k; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--; y--;
    a[x][y] = 1;
    a[y][x] = 1;
  }
  for(int i = 0; i<n; i++)
    for(int j = i+1; j<n; j++) 
      for(int z = j+1; z<n; z++)
        if(a[i][j] == a[j][z] && a[j][z] == a[z][i]) {
          puts("YES");
          return 0;
        }
  puts("NO");
  return 0;
}