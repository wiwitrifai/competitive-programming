#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

char in[N], out[N];

bool graf[N][N];

void solve() {
  memset(graf, 0, sizeof graf);
  int n;
  scanf("%d", &n);
  scanf("%s %s", in, out);
  for (int i = 0; i < n; ++i) {
    for (int j = i-1; j <= i+1; j += 2) {
      if (j < 0 || j >= n) continue;
      graf[i][j] = (out[i] == 'Y' && in[j] == 'Y');
    }
  }
  for (int i = 0; i < n; ++i)
    graf[i][i] = true;
  while (true) {
    bool done = true;
    for (int k = 0; k < n; ++k) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          if (!graf[i][j] && graf[i][k] && graf[k][j]) {
            graf[i][j] = true;
            done = false;
          }
        }
      }
    }
    if (done)
      break;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j)
      printf("%c", graf[i][j] ? 'Y' : 'N');
    printf("\n");
  }
}

int main(int argc, char * argv[]) {
  clock_t starttime = clock();
  int seed = time(0);
  if (argc >= 2) {
    seed = atoi(argv[1]);
  }
  cerr << "random seed\t= " << seed << endl;
  srand(seed);

  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; ++tc) {
    printf("Case #%d:\n", tc);
    solve();
    fflush(stdout);
    cerr << "~ TC#" << tc << " done! execution time : " <<
      (double)(clock() - starttime) / CLOCKS_PER_SEC << " s " << endl;
  }
  return 0;
}
