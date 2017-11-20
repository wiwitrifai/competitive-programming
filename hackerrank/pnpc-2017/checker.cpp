#include <bits/stdc++.h>

using namespace std;

const long double eps = 1e-6;

int main(int nargs, char* argv[]) {
  printf("%s %s\n", argv[1], argv[2]);
  FILE * result = fopen(argv[1], "r");
  FILE * jury = fopen(argv[2], "r");
  double le, ri;
  int now = 1;
  int l, r;
  while ((l = fscanf(result, "%lf", &le)) == 1 && ((r = fscanf(jury, "%lf", &ri)) == 1)) {
    if (fabs(le - ri) > eps) {
      cerr << le << " " << ri << endl;
      printf("%d\n", now);
      break;
    }
    now++;
  }
  while (l != r) {
    cerr << le << " " << ri;
    puts("wow");
    (l = fscanf(result, "%lf", &le)) == 1 && ((r = fscanf(jury, "%lf", &ri)) == 1);
  }
  return 0;
}