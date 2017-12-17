#include <bits/stdc++.h>

using namespace std;

char s[] = "RYGBRYGBRYGB";
int dua[4][4] = {{2, 1, 4, 3}, {4, 1, 2, 3}, {4, 3, 2, 1}, {2, 3, 4, 1}};
char ans[555][555];

int n, m, d;
bool valid(int x, int y) {
  return x >= 0 && y >= 0 && x < n && y < m;
}

int main() {
  scanf("%d %d", &n, &m, &d); 
  if (d & 1) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if ((i + j) & 1)
          printf("R");
        else
          printf("Y");
      }
      printf("\n");
    }
    return 0;
  }
  if ((d % 4) == 2) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        printf("%c", s[dua[i%4][j%4]]);
      }
      printf("\n");
    }
  }
  else {
    int a = 1, b = 2, c = 3, d = 4;
    for (int i = -max(n, m); i < max(n, m); i += d-1) {
      swap(a, c);
      swap(b, d);
      int u = a, v = b;
      for (int j = 0; j < m; j += d) {
        if (i+j >= max(n, m)) break;
        swap(u, v);
        for (int k = 0; k < d; k++) {
          int x = i+j+k, y = j+k;
          if (valid(x, y))
            ans[x][y] = s[u];
        }
      }
      u = a, v = b;
      for (int j = 0; j < m; j += d) {
        if (i+j >= max(n, m)) break;
        swap(u, v);
        for (int k = 0; k < d; k++) {
          int x = i-j-k, y = j+k;
          if (valid(x, y))
            ans[x][y] = s[u];
        }
      }
    }
    for (int i = 0; i < m; i++) {

    }
  }
  return 0;
}