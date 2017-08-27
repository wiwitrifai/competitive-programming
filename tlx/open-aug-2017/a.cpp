#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int bit[N];
int a[N], n;

void update(int x, int val) {
  for (; x <= n; x += x&-x)
    bit[x] = max(bit[x], val);
}
int get(int x) {
  int ret = 0;
  for (; x; x -= x&-x)
    ret = max(ret, bit[x]);
  return ret;
}

int l[N], r[N], q, last[N], ans[N];
vector<int> que[N], upd[N];

int main() {
  scanf("%d %d", &n, &q);
  memset(last, 0, sizeof last);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a+i);
    if (a[i] == 1)
      last[1] = i;
    else
      last[a[i]] = max(last[a[i]], last[a[i]-1]);
    if (last[a[i]] != 0)
      upd[last[a[i]]].push_back(i);
  }
  for (int i = 0; i < q; i++) {
    scanf("%d %d", l+i, r+i);
    que[l[i]].push_back(i);
  }
  memset(bit, 0, sizeof bit);
  for (int i = n; i >= 1; i--) {
    for (int z : upd[i]) {
      update(z, a[z]);
    }
    for (int z : que[i]) {
      ans[z] = get(r[z]);
    }
  }
  for (int i = 0; i < q; i++) 
    printf("%d\n", ans[i]);
  return 0;
}