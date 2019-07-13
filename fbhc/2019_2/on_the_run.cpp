#include <bits/stdc++.h>

using namespace std;


void solve() {
  int n, m, k, a, b;
  scanf("%d %d %d", &n, &m, &k);
  vector<int> odd;
  for (int i = 0; i <= k; ++i) {
    scanf("%d %d", &a, &b);
    odd.push_back((a+b) & 1);
  }
  if (k == 1)
    puts("N");
  else {
    bool ok = 1;
    for (int i = 0; i + 1 < (int)odd.size(); ++i)
      ok &= odd[i] == odd[i+1];
    puts(ok ? "Y" : "N");
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
    printf("Case #%d: ", tc);
    solve();
    fflush(stdout);
    cerr << "~ TC#" << tc << " done! execution time : " <<
      (double)(clock() - starttime) / CLOCKS_PER_SEC << " s " << endl;
  }
  return 0;
}
