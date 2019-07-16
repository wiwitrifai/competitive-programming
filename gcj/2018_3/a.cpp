#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, mod = 1e9 + 7;

int x[N], y[N], n;

void solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d %d", x+i, y+i);
  int ans = max(*max_element(x, x+n) - * min_element(x, x+n),
    *max_element(y, y+n) - * min_element(y, y+n));
  printf("%d\n", (ans + 1) / 2);

}

int main() {
  time_t startt = clock();
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    printf("Case #%d: ", tc);
    solve();
    cerr << "~ #" << tc << " done! time : " << (double)(clock()-startt) * 1000/CLOCKS_PER_SEC << " ms" << endl;
  }
  return 0;
}