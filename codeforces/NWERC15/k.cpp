#include <bits/stdc++.h>

using namespace std;

const int N = 2024;
const long long INF = 1000000000000000001LL;

int r, m, s, d, n;
int b[N];
vector<int> g[N];
int x[N], y[N];

long long mul(long long le, long long ri) {
  if (le == 0) return 0;
  if (INF/le < ri)
    return INF;
  return le * ri;
}

int main() {
  scanf("%d %d %d %d %d", &r, &s, &m, &d, &n);
  int tot = s + m + d;
  for (int i = 1; i <= r; i++)
    scanf("%d", b+i);
  for (int i = 0; i < tot; i++) {
    int k;
    scanf("%d", &k);
    g[i].clear();
    while (k--) {
      int v;
      scanf("%d", &v);
      g[i].push_back(v);
    }
  }
  for (int i = 0; i < n; i++) {
    scanf("%d %d", x+i, y+i);
    x[i]--;
    y[i]--;
  }
  long long ans = 0;
  for (int i = 0; i < s; i++) {
    for (int j = s; j < s+m; j++) {
      for (int k = s+m; k < tot; k++) {
        set<int> st;
        st.insert(i);
        st.insert(j);
        st.insert(k);
        bool ok = 1;
        for (int z = 0; z < n; z++) {
          if (st.count(x[z]) && st.count(y[z])) {
            ok = 0;
            break;
          }
        }
        if (!ok) continue;
        st.clear();
        for (int z : g[i])
          st.insert(z);
        for (int z : g[j])
          st.insert(z);
        for (int z : g[k])
          st.insert(z);
        long long cur = 1;
        for (int z : st) {
          cur = mul(cur, b[z]);
        }
        ans = min(INF, ans + cur);
      }
    }
  }
  if (ans >= INF)
    puts("too many");
  else
    cout << ans << endl;
  return 0;
}