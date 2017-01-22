#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 5;

long long a[N], b[N], r[N], c[N], x[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    int s = n * m;
    for (int i = 0; i < s; i++)
      scanf("%lld", a+i);
    for (int i = 0; i < s; i++)
      scanf("%lld", b+i); 
    for (int i = 0; i < m; i++) {
      c[i] = b[i] - a[i];
    }
    for (int i = 0; i < n; i++) {
      r[i] = b[i * m] - (a[i * m] + c[0]);
    }
    bool ok = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        a[i * m + j] += r[i] + c[j];
        if (a[i * m + j] != b[i * m + j]) {
          ok = 0;
          break;
        }
      }
    }
    if (!ok) {
      puts("-1");
      continue;
    }
    int off = 0;
    for (int i = 0; i < n; i++) {
      x[i] = r[i];
    } 
    for (int i = 0; i < m; i++)
      x[i + n] = -c[i];
    n += m;
    sort(x, x+n);
    long long all = 0;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      all += x[i];
      ans += abs(x[i]);
    }
    long long sum = 0;
    long long cnt = 0;
    for (int i = 0; i < n; i++) {
      all -= x[i];
      sum += x[i];
      cnt++;
      ans = min(ans, abs(sum - cnt * x[i]) + abs(all - x[i] * (n-cnt)));
    }
    printf("%lld\n", ans);

  }

  return 0;
}