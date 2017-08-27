#include <bits/stdc++.h>

using namespace std;

const int N = 4;
int x[N], y[N], z[N];

int main() {
  time_t startt = clock();
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    for (int i = 0; i < 3; i++)
      scanf("%d %d %d", x+i, y+i, z+i);
    int mi = x[0], ma = x[0];
    for (int i = 0; i < 3; i++)
      mi = min(x[i], mi), ma = max(ma, x[i]);
    printf("Case #%d: %.20lf\n", tc, (double)(ma - mi) / 6);
    cerr << "~ #" << tc << " done! time : " << (double)(clock()-startt) * 1000/CLOCKS_PER_SEC << " ms" << endl;
  }
  return 0;
}