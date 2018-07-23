#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int main() {
  clock_t startt = clock();
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; ++tc) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i <= n; ++i)
      scanf("%*d");
    printf("Case #%d: %d\n", tc, n & 1);
    if (n & 1)
      puts("0.0");
    cerr << " TC# " << tc << " done ! time : " << (double)(clock() - startt) * 1000.0 / CLOCKS_PER_SEC << " ms " << endl;
  }
  return 0;
}