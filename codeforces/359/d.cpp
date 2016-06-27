#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int inf = 1e9 + 7;

int n, x[2*N], y[N], z, m, k;
pair<int, int> p[N];
long long ans[N], cnt[N], sum[N];

void add(int cur, int yy, int mul = 1) {
  int l = upper_bound(y, y+m, yy-k) - y;
  int r = lower_bound(y, y+m, yy) - y;
  int pos = r;
  int now = 0;
  for(int i = l; i<=r; i++)
    now += cnt[i];
  int posy = yy-k+1;
  while(posy <= yy) {
    while(r+1 < m && posy + k > y[r+1]) {
      r++;
      now += cnt[r];
    }
    while(y[l] < posy) {
      now -= cnt[l];
      l++;
    }
    int next = min(max(yy+1, posy+k), min(y[l]+1, r+1 < m ? y[r+1] - k +1 : inf));
    ans[now] -= 1LL*(x[z]-cur)*(next-posy);
    ans[now+mul] += 1LL*(x[z]-cur) * (next - posy);
    posy = next;
  }
  cnt[pos] += mul;
}

int main() {
  scanf("%d%d", &n, &k);
  for(int i = 0; i<n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    p[i] = make_pair(u, v);
    y[i] = v;
    x[i*2] = u;
    x[i*2 + 1] = u + k;
  }
  sort(p, p+n);
  sort(y, y+n);
  sort(x, x+2*n);
  m = unique(y, y+n) - y;
  int cur = p[0].first;
  z = unique(x, x+2*n)-x-1;
  int l, r;
  l = 0, r = 0;
  for(int i = 0; i<z; i++) {
    int cur = x[i];
    while(r < n && p[r].first <= cur) {
      add(cur, p[r].second, 1);
      r++;
    }
    while(p[l].first + k <= cur) {
      add(cur, p[l].second, -1);
      l++;
    }
  }
  for(int i= 1; i<=n; i++)
    cout << ans[i] << " ";
  cout << endl;
  return 0;
}