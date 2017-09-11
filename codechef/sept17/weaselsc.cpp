#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, K = 55;
const long long inf = 1e18;

struct line {
  line(long long a = 0, long long b = 0) : a(a), b(b) {}
  long long a, b, get(long long x) {
    return a*x + b;
  }
  long double getd(long double x) {
    return x * a + b;
  }
};

struct convex_hull_trick {
  line hull[N];
  int size;
  convex_hull_trick(int sz = 0) : size(0) {
  }
  bool isbad(line prev, line cur, line next) {
    return (prev.b - cur.b) * (next.a - cur.a) >= (cur.b - next.b) * (cur.a - prev.a);
  }
  void add(line nl) {
    hull[size++] = nl;
    while(size > 2 && isbad(hull[size-3], hull[size-2], hull[size-1])) {
      hull[size-2] = nl, size--;
    }
  }

  long long query(long long x) {
    int l, r;
    l = 0; r = size-1;
    while(l < r) {
      int m = (l + r) >> 1;
      if(hull[m].get(x) <= hull[m+1].get(x))
        l = m+1;
      else
        r = m;
    }
    return hull[l].get(x);
  }
};

convex_hull_trick chull[K];
int n, k, ri[N], le[N];
long long h[N], dp[N][K];
vector<int> upd[N], yo[N];

void dnc(int l, int r) {
  if (l == r) {
    return;
  }
  int mid = (l + r)/2;
  dnc(l, mid);
  for (int i = l; i <= mid; i++) {
    yo[i].clear();
  }
  for (int j = 0; j < k; j++)
    chull[j].size = 0;
  for (int i = mid+1; i <= r; i++) {
    for (int id : upd[i]) {
      int ll = max(le[id], l);
      if (ll <= mid)
        yo[ll].push_back(id);
    }
  }
  for (int i = mid; i >= l; i--) {
    for (int j = 0; j < k; j++) {
      chull[j].add(line(-i, dp[i][j]));
      for (int id : yo[i]) {
        long long cur = chull[j].query(h[id]) + 1LL * ri[id] * h[id];
        if (cur > dp[ri[id]][j+1]) {
          dp[ri[id]][j+1] = cur;
        }
      }
    }
  }
  dnc(mid+1, r);
}
long long solve() {
  for (int i = 0; i <= k; i++)
    chull[i].size = 0;
  stack<int> st;
  for (int i = n-1; i >= 0; i--) {
    while (!st.empty() && h[st.top()] >= h[i]) st.pop();
    ri[i] = st.empty() ? n-1 : st.top() - 1;
    st.push(i);
    upd[i].clear();
  }
  while (!st.empty()) st.pop();
  for (int i = 0; i < n; i++) {
    while (!st.empty() && h[st.top()] >= h[i]) st.pop();
    le[i] = st.empty() ? 0 : st.top()+1;
    st.push(i);
    upd[ri[i]].push_back(i);
  }
  for (int i = 0; i < n; i++) {
    dp[i][0] = 0;
    for (int id : upd[i])
      dp[i][0] = max(dp[i][0], 1LL * (ri[id] - le[id] + 1) * h[id]);
    for (int j = 0; j < k; j++)
      dp[i][j+1] = dp[i][j];
  }
  dnc(0, n-1);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= k; j++) {
      ans = max(ans, dp[i][j]);
    }
  }
  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
      scanf("%d", h+i);
    }
    long long ans = solve();
    reverse(h, h+n);
    ans = max(ans, solve());
    printf("%lld\n", ans);
  }
  return 0;
}