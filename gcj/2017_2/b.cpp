#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

int n, c, m;
int r[N], a[N], p[N], b[N];

int main() {
  time_t startt = clock();
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    memset(r, 0, sizeof r);
    memset(a, 0, sizeof a);
    scanf("%d %d %d", &n, &c, &m);
    for (int i = 0; i < m; i++)
      scanf("%d %d", p+i, b+i), r[p[i]]++, a[b[i]]++;
    int le = 0;
    for (int i = 1; i <= c; i++)
      le = max(le, a[i]);
    int ri = m;
    while (le < ri) {
      int mid = (le + ri) / 2;
      int sum = 0;
      bool ok = 1;
      for (int i = 1; i <= n; i++) {
        sum += r[i];
        if (sum > i * mid) {
          ok = 0;
          break;
        }
      }
      if (ok)
        ri = mid;
      else
        le = mid + 1;
    }
    int need = 0;
    for (int i = 1; i <= n; i++)
      need += max(0, r[i] - le);
    printf("Case #%d: %d %d\n", tc, le, need);
    cerr << "~ #" << tc << " done! time : " << (double)(clock()-startt) * 1000/CLOCKS_PER_SEC << " ms" << endl;
  }
  return 0;
}