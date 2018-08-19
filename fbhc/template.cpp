#include <bits/stdc++.h>

using namespace std;

void solve(int tc) {
  printf("Case #%d: ", tc);
  int ans = 0;
  printf("%d\n", ans);
}

int main() {
  clock_t startt = clock();
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; ++tc) {
    solve(tc);
    fflush(stdout);
    cerr << " TC# " << tc << " done ! time : " << (double)(clock() - startt) / CLOCKS_PER_SEC << " s " << endl;
  }
  return 0;
}