#include <bits/stdc++.h>

using namespace std;

const int N = 305;

char a[N], b[N];
int mem[N][N][N];
pair<int, pair<int, int> > bef[N][N][N];
char val[N][N][N];

int dp(int x, int y, int z) {
  if(x <= 0)
    return 0;
  int & ret = mem[x][y][z];
  if(ret >= 0)
    return ret;
  ret = 0;
  int res;
  if(y > 0 && z > 0) {
    if(a[y] == b[z]) {
      res = dp(x-1, y-1, z-1) + 2;
      if(res > ret) {
        ret = res;
        bef[x][y][z] = {x-1, {y-1, z-1}};
        val[x][y][z] = a[y];
      }
    }
    res = dp(x, y-1, z-1);
    if(res > ret) {
      ret = res;
      bef[x][y][z] = bef[x][y-1][z-1];
      val[x][y][z] = val[x][y-1][z-1];
    }
  }
  if(y > 0)
  {
    res = dp(x-1, y-1, z) + 1;
    if(res > ret) {
      ret = res;
      bef[x][y][z] = {x-1, {y-1, z}};
      val[x][y][z] = a[y];
    }
    res = dp(x, y-1, z);
    if(res > ret) {
      ret = res;
      bef[x][y][z] = bef[x][y-1][z];
      val[x][y][z] = val[x][y-1][z];
    }
  }

  if(z > 0)
  {
    res = dp(x-1, y, z-1) + 1;
    if(res > ret) {
      ret = res;
      bef[x][y][z] = {x-1, {y, z-1}};
      val[x][y][z] = b[z];
    }
    res = dp(x, y, z-1);
    if(res > ret) {
      ret = res;
      bef[x][y][z] = bef[x][y][z-1];
      val[x][y][z] = val[x][y][z-1];
    }
  }
  res = dp(x-1, y, z);
  if(res > ret) {
    ret = res;
    bef[x][y][z] = {x-1, {y, z}};
    val[x][y][z] = 'a';
  }
  return ret;
}

char ans[N];

int main() {
  scanf("%s%s", a+1, b+1);
  int n = strlen(a+1);
  memset(mem, -1, sizeof mem);
  int res = dp(n, n, n);
  pair<int, pair<int, int> > now = {n, {n, n}};
  ans[n] = '\0';
  for(int i = n-1; i>=0; i--) {
    ans[i] = val[now.first][now.second.first][now.second.second];
    now = bef[now.first][now.second.first][now.second.second];
  }
  printf("%s\n", ans);
  return 0;
}