#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6, mod = 1e9 + 7;

char v[N];
int n, k;
int pw[N];

void read_input() {
  scanf("%d %d", &n, &k);
  scanf("%s", v);
}
int f[N];

void solve() {
  f[n] = n;
  int mini = n + k;
  int ans = 0;
  for (int i = n-1; i >= 0; --i) {
    f[i] = f[i+1]-1;
    if (v[i] == 'B') {
      if (f[i] + 2 <= mini) {
        f[i] += 2;
      }
      else {
        ans = (ans + pw[i+1]) % mod;
      }
    }
    mini = min(mini, f[i] + k);
  }
  printf("%d\n", ans);
}

int main(int argc, char * argv[]) {
  clock_t starttime = clock();
  int seed = time(0);
  if (argc >= 2) {
    seed = atoi(argv[1]);
  }
  cerr << "random seed\t= " << seed << endl;
  srand(seed);

  pw[0] = 1;
  for (int i = 1; i < N; ++i)
    pw[i] = (pw[i-1] * 2LL) % mod;
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; ++tc) {
    printf("Case #%d: ", tc);
    read_input();
    solve();
    fflush(stdout);
    cerr << "~ TC#" << tc << " done! execution time : " <<
      (double)(clock() - starttime) / CLOCKS_PER_SEC << " s " << endl;
  }
  return 0;
}
