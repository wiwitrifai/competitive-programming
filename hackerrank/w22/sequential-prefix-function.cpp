#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], n, m;
int z[N], ans[N];

int main() {
  scanf("%d", &n);
  m = 0;
  ans[0] = 0;
  memset(z, -1, sizeof z);
  while (n--) {
    char c;
    int x;
    scanf(" %c", &c);
    if (c == '-') {
      if (m) {
        ans[m] = 0;
        m--;
        z[m] = -1;
      }
    }
    else {
      scanf("%d", &x);
      a[m] = x;
      int now = m - ans[m], l = now, r = m-1;
      m++;
      if (m == 1) {
        ans[m] = 0;
        z[0] = 0;
      }
      else {
        while (now < m) {
          r++;
          while (r < m && a[r-l] == a[r]) r++;
          r--;
          // cerr << now << " " << l << " " << r << " " << m << endl;
          if (r == m-1) {
            ans[m] = r-l+1;
            break;
          }
          if (l == now) {
            z[now] = r-l+1;
            now++;
          }
          else {
            z[now] = z[now-l];
            if (now + z[now] > r) {
              l = now;
            }
            else
              now++;
          }
        }
      }
    }
    printf("%d\n", ans[m]);
  }

  return 0;
}