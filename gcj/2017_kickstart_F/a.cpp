#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 4;

int bit[N];

void upd(int x, int val) {
  for (; x < N; x += x&-x)
    bit[x] += val;
}
int get(int x) {
  int ret = 0;
  for (int i = 1 << 18; i > 0; i >>= 1) {
    if ((i + ret) >= N) continue;
    if (bit[i+ret] <= x) {
      ret += i;
      x -= bit[ret];
    }
  }
  return ret;
}
int a[N];

int main() {
  time_t startt = clock();
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", a+i);
    }
    memset(bit, 0, sizeof bit);
    int lo = 1, hi = n;
    for (int i = 1; i <= n; i++)
      upd(i, 1);
    bool ok = 1;
    while (n > 0) {
      int mid = (n+1)/2;
      int id = get(mid-1)+1;
      if (a[id] == lo)
        lo++;
      else if (a[id] == hi)
        hi--;
      else
        ok = 0;
      upd(id, -1);
      n--;
    }
    printf("Case #%d: %s\n", tc, ok ? "YES" : "NO");
    cerr << "~ #" << tc << " done! time : " << (double)(clock()-startt) * 1000/CLOCKS_PER_SEC << " ms" << endl;
  }
  return 0;
}