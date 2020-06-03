#include <bits/stdc++.h>

using namespace std;

int n, m, k;
char s[105][105];

int main() {
  scanf("%d%d%d", &n, &m, &k);
  k -= 2;
  for(int i = 0; i<n; i++) {
    scanf("%s", s[i]);
  }
  int sum, ax = 1, ay = 1, ans;
  sum = 0;
  for(int i = 1; i<=k; i++)
    for(int j = 1; j<=k; j++)
      sum += (s[i][j] == '*');
  ans = sum;  
  for(int i = 1; i<n-k; i++) {
    int first = sum;
    for(int j = 1; j<m-k; j++) {
      if(sum > ans) {
        ans = sum;
        ax = i;
        ay = j;
      }
      for(int z = 0; z < k; z++) {
        sum += (s[i+z][j+k] == '*');
        sum -= (s[i+z][j] == '*');
      }
    }
    sum = first;
    for(int z = 1; z <= k; z++) {
      sum += (s[i+k][z] == '*');
      sum -= (s[i][z] == '*');
    }
  }
  s[ax-1][ay-1] = s[ax-1][ay+k] = s[ax+k][ay-1] = s[ax+k][ay+k] = '+';
  for(int i = 0; i<k; i++) {
    s[ax-1][ay+i] = '-';
    s[ax+k][ay+i] = '-';
  }
  for(int i = 0; i<k; i++) {
    s[ax+i][ay-1] = '|';
    s[ax+i][ay+k] = '|';
  }
  printf("%d\n", ans);
  for(int i = 0; i<n; i++)
    printf("%s\n", s[i]);
  return 0;
}