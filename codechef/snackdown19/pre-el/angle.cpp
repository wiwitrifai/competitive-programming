#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

int a[N];
int p, q, n;
int ord[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d %d", &n, &p, &q);
    for (int i = 0; i < n; ++i) {
      scanf("%d", a+i);
      ord[i] = i;
    }
    sort(ord, ord+n, [&](int x, int y) {
      return a[x] < a[y];
    });
    int ansx = -1, ansy = -1, ansz = -1;
    long double best = 1e18;
    for (int i = 0; i < n; ++i) {
      for (int j = i+1; j < n; ++j) {
        long long y = a[i];
        long long z = a[j];
        long long v = (1LL * y * y + 1LL * z * z) * q - 1LL * p * 2 * y * z;
        int l = 0, r = n;
        while (l < r) {
          int mid = (l + r) >> 1;
          long long x = a[ord[mid]];
          if (v < 1LL * x * x * q)
            r = mid;
          else
            l = mid + 1;
        }
        --l;
        while (l >= 0) {
          if (ord[l] == i | ord[l] == j) {
            --l;
            continue;
          } 
          break;
        }
        if (l < 0) continue;
        l = ord[l];
        long long x = a[l];
        long double cur = v - 1LL * x * x * q;
        cur /= 1LL * y * z;
        if (cur < best) {
          best = cur;
          ansx = l;
          ansy = i;
          ansz = j;
        }
      }
    }
    cerr << best << endl;
    if (ansx == -1) {
      puts("-1");
    }
    else
      printf("%d %d %d\n", ansx+1, ansy+1, ansz+1);
  }
  return 0;
}