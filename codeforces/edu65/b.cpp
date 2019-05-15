#include <bits/stdc++.h>

using namespace std;

vector<int> v = {4, 8, 15, 16, 23, 42};

int mul[7][7];

int ask(int x, int y) {
  printf("? %d %d\n", x+1, y+1);
  fflush(stdout);
  int res;
  scanf("%d", &res);
  return res;
}

int main() {
  int all = 1;
  for (int x : v)
    all *= x;
  memset(mul, -1, sizeof mul);
  mul[0][1] = mul[1][0] = ask(0, 1);
  mul[2][3] = mul[3][2] = ask(2, 3);
  mul[4][5] = mul[5][4] = all / mul[0][1] / mul[2][3];
  mul[0][2] = mul[2][0] = ask(0, 2);
  mul[1][3] = mul[3][1] = mul[0][1] * mul[2][3] / mul[0][2];
  mul[1][4] = mul[4][1] = ask(1, 4);
  do {
    bool ok = 1;
    for (int i = 0; i < 6; ++i) {
      for (int j = 0; j < 6; ++j) {
        if (mul[i][j] == -1) continue;
        ok &= mul[i][j] == v[i] * v[j];
      }
    }
    if (ok) {
      printf("! ");
      for (int i = 0; i < 6; ++i) {
        printf("%d%c", v[i], i == 5 ? '\n' : ' ');
      }
      fflush(stdout);
      return 0;
    }
  } while (next_permutation(v.begin(), v.end()));
  assert(false);
  return 0;
}
