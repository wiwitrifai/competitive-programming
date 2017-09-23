/**
 * Upsolve after contest
 * Author  : Wiwit Rifa'i
 * Problem : G - Pertukaran Chanek
 * Status  : ?
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

long long bit[N];
int n;
void upd(int x, long long v) {
  for (; x <= n; x+=x&-x)
    bit[x] = max(bit[x], v);
}
long long get(int x) {
  long long ret = 0;
  for (; x; x-=x&-x)
    ret = max(ret, bit[x]);
  return ret;
}
vector<int> u[N], q[N];
int l[N], r[N], a[N];
long long ans[N], sum[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int k, m;
    scanf("%d %d %d", &n, &k, &m);
    sum[0] = 0;
    for (int i = 1; i <= n; i++)
      scanf("%d", a+i), sum[i] = sum[i-1] + a[i];
    for (int i = 1; i <= n; i++)
      u[i].clear(), q[i].clear();
    for (int i = 0; i < m; i++) {
      scanf("%d %d", l+i, r+i);
      q[l[i]].push_back(i);
    }
    stack<int> st;
    for (int i = 1; i <= n; i++) {
      while (!st.empty() && a[st.top()] <= a[i]) u[st.top()].push_back(i), st.pop();
      if (!st.empty())
        u[st.top()].push_back(i);
      st.push(i);
    }
    fill(bit, bit+n+1, 0);
    for (int i = n; i > 0; i--) {
      for (int ri : u[i]) {
        if (ri - i + 1 > k+1) continue;
        long long val = sum[ri-1] - sum[i];
        long long x = a[i], y = a[ri];
        if (x < y)
          swap(x, y);
        val += x * k + y * (k - (ri-i-1));
        upd(ri, val);
      }
      for (int id : q[i]) {
        ans[id] = get(r[id]);
      }
    }
    for (int i = 0; i < m; i++)
      printf("%lld\n", ans[i]);
  }
  return 0;
}