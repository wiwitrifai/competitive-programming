#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;
int d[N];

int main() {
  time_t startt = clock();
  cerr << "Preprocessing done! time: " << (double)(clock() - startt) * 1000 / CLOCKS_PER_SEC << " ms" << endl;
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", d+i);
    }
    int ans = 0;
    int cnt = 0, last = -1; 
    for (int i = 0; i < n; i++) {
      if (cnt == 4) {
        last = -1;
        cnt = 0;
      }
      if (last == -1) {
        last = d[i];
        cnt = 1;
        continue;
      }
      if (d[i] <= last) {
        ans += 4-cnt;
        last = d[i];
        cnt = 1;
        continue;
      }
      int dd = d[i] - last;
      int need = (dd - 1) / 10;
      if (cnt + need + 1 <= 4) {
        ans += need;
        cnt += need + 1;
        last = d[i];
      }
      else {
        ans += 4-cnt;
        cnt = 1;
        last = d[i];
      }
    }
    if (cnt)
      ans += 4- cnt;
    printf("Case #%d: %d\n", tc, ans);

    cerr << "TC#" << tc << " done! time: " << (double)(clock() - startt) * 1000 / CLOCKS_PER_SEC << " ms" << endl;
  }
  cerr << "Finihed!" << endl;
  return 0;
}