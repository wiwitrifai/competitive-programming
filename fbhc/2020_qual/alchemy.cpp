#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

char s[N];

void solve() {
  int n;
  scanf("%d %s", &n, s);
  int a = 0;
  for (int i = 0; i < n; ++i)
    a += s[i] == 'A';
  int b = n - a;
  puts(abs(a-b) == 1 ? "Y" : "N");
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
    printf("Case #%d: ", tc);
    solve();
    fflush(stdout);
    cerr << "~ TC#" << tc << " done! execution time : " <<
      (double)(clock() - starttime) / CLOCKS_PER_SEC << " s " << endl;
  }
  return 0;
}
