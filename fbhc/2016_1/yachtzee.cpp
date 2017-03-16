#include <bits/stdc++.h>
 
using namespace std;

const int N = 1e6 + 6;

int c[N];
 
int main() {
  time_t startt = clock();
  cerr << "Preprocessing done! time: " << (double)(clock() - startt) * 1000 / CLOCKS_PER_SEC << " ms" << endl;
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    long long tot = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", c+i);
      tot += c[i];
    }
    long long sum = 0, pre = 0;
    for (int i = 0; i < n; i++) {
      if (cnta < 0) cnta = 0;
      if (cntb < 0) cntb = 0;
      cerr << cnta << " " << cntb << endl;
      if (cnta == cntb) {
        sum += 1LL * c[i] * c[i] * cnta;
      }
      else {
        assert(cnta == cntb + 1);
        long long sisa = b - cntb * tot - pre;
        sum += 1LL * c[i] * c[i] * cntb + sisa * sisa;
      }
      pre += c[i];
    }
    printf("Case #%d: %.9lf\n", tc, (double)sum/(b-a));
    cerr << "TC#" << tc << " done! time: " << (double)(clock() - startt) * 1000 / CLOCKS_PER_SEC << " ms" << endl;
  }
  cerr << "Finihed!" << endl;
  return 0;
}