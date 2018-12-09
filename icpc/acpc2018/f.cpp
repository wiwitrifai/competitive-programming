#include <bits/stdc++.h>

using namespace std;

void open_file(string filename) {
#ifndef LOCAL
  freopen(filename.c_str(), "r", stdin);
#endif
}

void close_file() {
#ifndef LOCAL
  fclose(stdin);
#endif
}

const int N = 303;

int a[N][N];

int main() {
  open_file("fetiera.in");
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        scanf("%d", a[i]+j);
      }
    }
    long long tot = n * (n + 1) / 2;
    tot *= tot;
    double ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        int cntl = (i + 1) * (j + 1);
        int cntr = (n - i) * (n - j);
        double p = (double) cntl * cntr / tot,  q = 1 - p;
        double odd = 0, even = 1;
        for (int z = 0; z < k; z++) {
          double todd = even * p + odd * q;
          double teven = even * q + odd * p;
          odd = todd;
          even = teven;
        }
        if (a[i][j])
          ans += even;
        else
          ans += odd;
      }
    }
    printf("%.5lf\n", ans);
  }
  close_file();
  return 0;
}