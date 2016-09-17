#include <bits/stdc++.h>

using namespace std;

const int N = 505;
const long long inf = 1e9 * N * N + 5;

int a[N][N], n, p;
int h[N], v[N], ansh[N], ansv[N];
long long ans;
long long sumh[N][N], sumv[N][N];
long long sum[N];

int main() {
  ans = 1e17;
  int t = 17;
  scanf("%d %d", &n, &p);
  p--;
  for (int i = 0; i < n; i++) {
    sumh[i][0] = 0;
    for (int j = 0; j < n; j++) {
      scanf("%d", a[i]+j);
      sumh[i][j+1] = sumh[i][j] + a[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    sumv[0][i];
    for (int j = 0; j < n; j++) {
      sumv[j+1][i] = sumv[j][i] + a[j][i];
    }
  }
  for (int i = 0; i <= p; i++)
    h[i] = i+1;
  h[p] = n;
  v[p] = n;
  while (t--) {
    long long lo = 0, hi = inf;
    while (lo < hi) {
      long long mid = (lo + hi) >> 1;
      for (int i = 0; i <= p; i++)
        sum[i] = 0;
      int iv = 0;
      bool ok = true;
      for (int i = 0; i < n; i++) {
        bool reset = false;
        for (int j = 0; j <= p; j++) {
          sum[j] += sumh[i][h[j]] - sumh[i][j ? h[j-1] : 0];
          if (sum[j] > mid) {
            reset = true;
          }
        }
        if (reset) {
          for (int j = 0; j <= p; j++) {
            sum[j] = sumh[i][h[j]] - sumh[i][j ? h[j-1] : 0];
            if (sum[j] > mid)
              ok = false;
          }
          v[iv++] = i-1;
        }
        if (iv >= p) {
          ok = false;
          break;
        }
      }
      if (ok)
        hi = mid;
      else
        lo = mid + 1;
    }
    if (ans > lo) {
      cerr << lo << endl;
      ans = lo;
      for (int i = 0; i <= p; i++) {
        ansv[i] = v[i];
        cerr << v[i] << " ";
      }
      for (int i = 0; i <= p; i++) {
        ansh[i] = h[i];
        cerr << h[i] << " ";
      }
      cerr << endl;
    }
    cerr << lo << " ";
    lo = 0, hi = inf;
    while (lo < hi) {
      long long mid = (lo + hi) >> 1;
      for (int i = 0; i <= p; i++)
        sum[i] = 0;
      int ih = 0;
      bool ok = true;
      for (int i = 0; i < n; i++) {
        bool reset = false;
        for (int j = 0; j <= p; j++) {
          sum[j] += sumv[v[j]][i] - sumv[j ? v[j-1] : 0][i];
          if (sum[j] > mid) {
            reset = true;
          }
        }
        if (reset) {
          for (int j = 0; j <= p; j++) {
            sum[j] = sumv[v[j]][i] - sumv[j ? v[j-1] : 0][i];
            if (sum[j] > mid)
              ok = false;
          }
          h[ih++] = i-1;
        }
        if (ih >= p) {
          ok = false;
          break;
        }
      }
      if (ok)
        hi = mid;
      else
        lo = mid + 1;
    }
    cerr << lo << endl;
    if (ans > lo) {
      cerr << lo << endl;
      ans = lo;
      for (int i = 0; i <= p; i++) {
        ansv[i] = v[i];
        cerr << v[i] << " ";
      }
      for (int i = 0; i <= p; i++) {
        ansh[i] = h[i];
        cerr << h[i] << " ";
      }
      cerr << endl;
    }
  }
  memcpy(h, ansh, sizeof h);
  memcpy(v, ansv, sizeof v);
  h[0] = max(h[0], 1);
  v[0] = max(v[0], 1);
  for (int i = 1; i <= p; i++) {
    h[i] = max(h[i], h[i-1] + 1);
    v[i] = max(v[i], v[i-1] + 1);
  }
  h[p] = v[p] = n;
  for (int i = p-1; i >= 0; i--) {
    h[i] = min(h[i], h[i+1]-1);
    v[i] = min(v[i], v[i+1]-1);
  }
  for (int i = 0; i < p; i++)
    printf("%d ", h[i]);
  printf("\n");
  for (int i = 0; i < p; i++)
    printf("%d ", v[i]);
  printf("\n");
  return 0;
}