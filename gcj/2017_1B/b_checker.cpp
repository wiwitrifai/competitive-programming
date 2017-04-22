#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

char s[N], tmp[N], tmp2[N];

bool ok[256][256];

int main() {
  ok['R']['Y'] = 1;
  ok['Y']['R'] = 1;
  ok['R']['B'] = 1;
  ok['B']['R'] = 1;
  ok['R']['G'] = 1;
  ok['G']['R'] = 1;
  
  ok['Y']['B'] = 1;
  ok['B']['Y'] = 1;
  ok['Y']['V'] = 1;
  ok['V']['Y'] = 1;

  ok['B']['O'] = 1;
  ok['O']['B'] = 1;
  int tc = 1;
  while (scanf("%s %s %s", tmp, tmp2, s) == 3) {
    int n = strlen(s);
    if (string(s) == string("IMPOSSIBLE")) {
      printf("%d IMPOSSIBLE\n", tc);
      continue;
    }
    bool cek = 1;
    for (int i = 0; i < n; i++) {
      cek &= ok[s[i]][s[(i+1)%n]];
    }
    printf("%d %s\n", tc, cek ? "YES" : "NO");
    assert(cek);
  }
  return 0;
}