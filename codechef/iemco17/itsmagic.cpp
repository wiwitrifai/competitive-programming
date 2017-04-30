#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 7;
struct fen {
  int n;
  long long bit[N];
  fen(int n = N-1) : n(n) {
    memset(bit, 0, sizeof bit);
  }
  void reset() {
    memset(bit, 0, sizeof bit);
  }
  void upd(int x, int v) {
    for (; x <= n; x+=x&-x)
      bit[x] += v;
  }
  long long get(int x) {
    long long r = 0;
    for (; x; x-=x&-x)
      r += bit[x];
    return r;
  }
};

bool magic[N];
bool prime[N];
int to[N], a[N];
fen bm, bs;
int main() {
  for (int i = 0; i < N; i++) {
    int x = i;
    int last = -1;
    magic[i] = 1;
    while (x) {
      int r = x % 10;
      x /= 10;
      if (last != -1 && abs(last-r) != 1) {
        magic[i] = 0;
        break;
      }
      last = r;
    }
  }
  fill(prime, prime+N, true);
  prime[0] = prime[1] = 0;
  for (int i = 2; i < N; ++i) if (prime[i]) {
    for (int j = i+i; j < N; j += i) {
      prime[j] = false;
    }
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, q;
    scanf("%d %d", &n, &q);
    int p, k;
    for (int i = 0; i <= n; i++) {
      if (magic[i]) {
        if (prime[i]) p = i;
        else k = i;
      }
      if (prime[i]) to[i] = p;
      else to[i] = k;
    }
    k = p = -1;
    for (int i = n; i >= 0; i--) {
      if (magic[i]) {
        if (prime[i]) p = i;
        else k = i;
      }
      if (prime[i]) to[i] = p == -1 ? to[i] : p;
      else to[i] = k == -1 ? to[i] : k;
    }
    bm.n = bs.n = n+1;
    bm.reset();
    bs.reset();
    for (int i = 0; i <= n; ++i) {
      a[i] = i;
      if (magic[i]) bm.upd(i+1, 1);
      bs.upd(i+1, i);
    }
    while (q--) {
      int x, y, z;
      scanf("%d %d", &x, &y);
      if (x == 1) {
        scanf("%d", &z);
        y--;
        printf("%lld %lld\n", bm.get(z)-bm.get(y), bs.get(z)-bs.get(y));
      }
      else {
        y--;
        // cerr << y << " " << a[y] << " -> " << to[a[y]] << endl;
        if (to[a[y]] != a[y]) {
          bs.upd(y+1, to[a[y]]-a[y]);
          bm.upd(y+1, 1);
          a[y] = to[a[y]];
        }
      }
    }
    puts(bm.get(n+1) * 2 > n+1 ? "happy" : "unhappy");
  }
  return 0;
}