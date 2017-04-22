#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;
const long long inf = 1e10;
long long d[N], x;
long long b[N];
int n;
bool ans[N];

int main() {
  scanf("%d %lld", &n, &x);
  for (int i = 0; i < n; i++)
    scanf("%lld", d+i);
  long long now = 1;
  for (int i = n-1; i >= 0; i--) {
    b[i] = now;
    if (d[i] < 2LL * now)
      now += d[i];
    now = min(now, x+1);
  }
  now = x;
  for (int i = 0; i < n; i++) {
    ans[i] = (now >= b[i]);
    // cerr << i << " " << now << " " << b[i] << endl;
    now = min(now, abs(now-d[i]));
  }
  if (now != 0)
    for (int i = 0; i < n; i++)
      ans[i] = 1;
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    int id;
    scanf("%d", &id);
    puts(ans[id-1] ? "YES" : "NO");
  }
  return 0;
}