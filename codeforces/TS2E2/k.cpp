#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

bool x[N][N];
int n, m;

bool solve(int a, int b) {
  if (b >= m) {
    b = 0;
    a++;
  }
  if (a >= n)
    return true;
  if (x[a][b])
    return solve(a, b+1);
  if (a+1 < n && b + 2 < m) {
    bool cek = true;
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 3; j++)
        cek &= !x[a+i][b+j];
    if (cek) {
      for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
          x[a+i][b+j] = true;
      bool res = solve(a, b+1);
      for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
          x[a+i][b+j] = false;
      if (res)
        return true;
    }
  }
  if (a+2 < n && b + 1 < m) {
    bool cek = true;
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 2; j++)
        cek &= !x[a+i][b+j];
    if (cek) {
      for (int i = 0; i < 3; i++)
        for (int j = 0; j < 2; j++)
          x[a+i][b+j] = true;
      bool res = solve(a, b+1);
      for (int i = 0; i < 3; i++)
        for (int j = 0; j < 2; j++)
          x[a+i][b+j] = false;
      if (res)
        return true;
    }
  }
  return false;
}

int main() {
  for (n = 1; n <= 20; n++) {
    for (m = 1; m <= 20; m++) {
      memset(x, 0, sizeof x);
      printf("%d ", solve(0, 0));
    }
    printf("\n");
  }

  return 0;
}