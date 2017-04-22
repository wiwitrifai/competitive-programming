#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int bit[N], n;
int get(int x) {
  int ret = 0;
  for (int i = 1<<19; i; i >>= 1)
    if (ret + i <= n && bit[ret+i] < x) {
      x -= bit[ret+i];
      ret += i;
    }
  return ret+1;
}
void upd(int x, int val) {
  for (; x <= n; x += x&-x)
    bit[x] += val;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long k;
    scanf("%d %lld", &n, &k);
    int now = 1, dir = 1;
    if (k < 0)
      k = -k, dir = -1;
    for (int i = 0; i <= n; i++)
      bit[i] =  0;
    for (int i = 1; i <= n; i++)
      upd(i, 1);
    for (int i = 1; i < n; i++) {
      long long move = (1LL * i * dir * k - dir) % (n-i+1);
      now += move;
      now %= (n-i+1);
      if (now <= 0)
        now += (n-i+1);
      int id = get(now);
      upd(id, -1);
      if (dir > 0) {
        if (now == 1)
          now = n-i;
        else
          now--;
      }
      now %= (n-i);
      dir = -dir;
    }
    printf("%d\n", get(1));
  }
  return 0;
}