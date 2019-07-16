#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, S = 2 * sqrt(N)+5;

int p[N];
int cnt[N];
set<int> st;
void add(int v, int k) {
  cnt[v] += k;
  if (cnt[v] > 0)
    st.insert(v);
  else
    st.erase(v);
}
int find(int x) {
  return p[x] < 0 ? x : p[x] = find(p[x]);
}

bool merge(int u, int v) {
  if ((u = find(u)) == (v = find(v))) return false;
  add(-p[u], -1);
  add(-p[v], -1);
  if (-p[v] < -p[u])
    swap(u, v);
  p[v] += p[u];
  p[u] = v;
  add(-p[v], +1);
  return true;
}

int main() {
  cerr << S << endl;
  int n, q;
  scanf("%d %d", &n, &q);
  memset(p, -1, sizeof p);
  add(1, n);
  int tot = n;
  while (q--) {
    int t, x, y;
    scanf("%d %d", &t, &x);
    if (t == 1) {
      scanf("%d", &y);
      tot -= merge(x, y);
    }
    else {
      long long ans = 0;
      auto it = st.begin(), it2 = it;
      int cur = 0;
      if (x > 0) {
        for (; it != st.end(); ++it) {
          while (it2 != st.end() && *it2 <= *it - x) {
            cur += cnt[*it2];
            ++it2;
          }
          ans += 1LL * cur * cnt[*it];
        }
      }
      else
        ans = 1LL * tot * (tot-1) / 2;
      printf("%lld\n", ans);
    }
  }
  return 0;
}