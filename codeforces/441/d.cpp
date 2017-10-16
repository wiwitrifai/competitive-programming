#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5, L = 31;

int last[N][L], a[N];
map<int, int> mp;

int bit[N];

int upd(int x, int v) {
  for (; x; x -= x&-x)
    bit[x] = max(bit[x], v);
}

int get(int x) {
  int ret = -1;
  for (; x < N; x += x&-x)
    ret = max(ret, bit[x]);
  return ret;
}

int main(){
  memset(bit, -1, sizeof bit);
  int n;
  vector<int> vx;
  scanf("%d", &n);
  for (int i = 0;i < n; i++) {
    scanf("%d", a+i);
    vx.push_back(a[i]);
  }
  sort(vx.begin(), vx.end());
  vx.erase(unique(vx.begin(), vx.end()), vx.end());
  for (int i = 0; i < L; i++)
    last[0][i] = -1;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (i)
      for (int j = 0; j < L; j++)
        last[i][j] = last[i-1][j];
    for (int j = 0; j < L; j++)
      if (a[i] & (1 << j))
        last[i][j] = i;
    int id = lower_bound(vx.begin(),vx.end(), a[i]) - vx.begin() + 1;
    upd(id, i);
    int now = a[i];
    int l = i-1;
    while (l >= 0) {
      int nx = -1;
      now |= a[l];
      for (int j = 0; j < L; j++) {
        if ((now & (1 << j)) == 0)
          nx = max(nx, last[l][j]);
        // cerr << l << " " << last[l][j] << endl;
      }
      id = lower_bound(vx.begin(),vx.end(), now) - vx.begin() + 1;
      int to = get(id);
      to = min(max(to, nx), l);
      // cerr << now << " " << i << " " << l << " " << nx << " " << to  << endl;
      ans += l-to;
      l = nx;
    }
  }
  cout << ans << endl;
  return 0;
}