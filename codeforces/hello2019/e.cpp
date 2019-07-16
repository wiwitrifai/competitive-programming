#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N];
int p[N], q[N];
int u[N], v[N];
bool used[N];
vector<vector<int> > ans;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", a+i);
      used[a[i]] = 0;
    }
    ans.clear();
    int x = 0, y = 0;
    while (n > 0) {
      x = y = 0;
      ans.push_back(vector<int>());
      for (int i = 0; i < n; ++i) {
        // cerr << a[i] << " ";
        assert(!used[a[i]]);
        int xx = lower_bound(p, p+x, a[i]) - p;
        int yy = lower_bound(q, q+y, -a[i]) - q;
        p[xx] = a[i];
        u[a[i]] = xx > 0 ? p[xx-1] : -1;
        if (xx == x) ++x;

        q[yy] = -a[i];
        v[a[i]] = yy > 0 ? -q[yy-1] : -1;
        if (yy == y) ++y;
      }
      // cerr << endl;
      // cerr << n << " " << x << " " << y << endl;
      if (x >= y) {
        int now = p[x-1];
        while (now > 0) {
          used[now] = 1;
          ans.back().push_back(now);
          now = u[now];
        }
        assert(ans.back().size() == x);
      }
      else {
        int now = -q[y-1];
        for (int i = 1; i <= n; ++i)
          // cerr << i << " -> " << v[i] << endl;
        while (now > 0) {
          used[now] = 1;
          ans.back().push_back(now);
          now = v[now];
        }
        assert(ans.back().size() == y);
      }
      int nn = n;
      n = 0;
      for (int i = 0; i < nn; ++i) {
        if (used[a[i]]) continue;
        a[n++] = a[i];
      }
      reverse(ans.back().begin(), ans.back().end());
      // cerr << nn << " to " << n << endl;
    }
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < ans.size(); ++i) {
      printf("%d", (int)ans[i].size());
      for (int x : ans[i])
        printf(" %d", x);
      printf("\n");
    }
  }
  return 0;
}