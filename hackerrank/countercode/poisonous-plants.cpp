#include <bits/stdc++.h>

using namespace std;
const int N = 1e5+5, inf = 1e9 + 1e7;

struct fen {
  int bit[N];
  int n;
    int minval;
  fen(int _n, int val) {
    n = _n;
        minval = val;
        for(int i = 0; i< N; i++)
            bit[i] = val;
  }
  int query(int x) {
    int ret = minval;
    for(; x<=n; x+= x&(-x)) ret = max(ret, bit[x]);
    return ret;
  }
  void update(int x, int val) {
    for(; x; x -= x&(-x)) bit[x] = max(bit[x], val);
  }
};
int p[N];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i<n; i++)
    scanf("%d", p+i);
  fen pes(n, -inf), die(n, 0);
  pes.update(1, -p[0]);
  die.update(1, inf);
  int ans = 0;
  for(int i = 1; i<n; i++) {
    int l, r;
    l = 1; r = i+1;
    while(l < r) {
      int mid = (l+r) >> 1;
      if(-pes.query(mid) < p[i])
        l = mid+1;
      else
        r = mid;
    }
    if(l == 1) {
      pes.update(i+1, -p[i]);
      die.update(i+1, inf);
      continue;
    }
    int res = die.query(l), willdie;
    if(res == 0)
      willdie = 1;
    else
      willdie = res+1;
        if(willdie < inf)
            ans = max(ans, willdie);
    pes.update(i+1, -p[i]);
    die.update(i+1, willdie);
  }
  printf("%d\n", ans);
  return 0;
}