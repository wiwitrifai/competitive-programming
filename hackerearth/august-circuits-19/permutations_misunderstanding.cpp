#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int, int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const int N = 1e5 + 5, S = sqrt(N) + 2;

int a[N];
ordered_set st[S][S];
vector<pair<int, int>> vs[S];
set<int> pos[N];
int bef[N], nbef[N];

void MovePos(int val, int from, int to) {
  {
    auto it = pos[val].find(from);
    assert(it != pos[val].end());
    auto nxt = it; ++nxt;
    if (nxt != pos[val].end()) {
      auto pre = it;
      bef[*nxt] = pre == pos[val].begin() ? -1 : *(--pre);
    }
    pos[val].erase(it);
  }
  {
    pos[val].insert(to);
    auto it = pos[val].find(to);
    assert(it != pos[val].end());
    auto pre = it;
    nbef[to] = pre == pos[val].begin() ? -1 : *(--pre);;
    auto nxt = it; ++nxt;
    if (nxt != pos[val].end()) {
      bef[*nxt] = to;
    }
  }
}

void SetVal(int x, int val) {
  int g = x / S;
  pair<int, int> now(a[x], x), vst(bef[x], x);
  int p = find(vs[g].begin(), vs[g].end(), now) - vs[g].begin();
  for (int i = p; i < (int)vs[g].size(); ++i)
    st[g][i].erase(vst);
  a[x] = val;
  now = make_pair(a[x], x);
  vs[g][p] = now;
  for (int i = p; i + 1 < (int)vs[g].size() && vs[g][i] > vs[g][i+1]; ++i) {
    swap(vs[g][i], vs[g][i+1]);
    swap(st[g][i], st[g][i+1]);
  }
  for (int i = p; i > 0 && vs[g][i] < vs[g][i-1]; --i) {
    swap(vs[g][i], vs[g][i-1]);
    swap(st[g][i], st[g][i-1]);
  }
  p = find(vs[g].begin(), vs[g].end(), now) - vs[g].begin();
  if (p == 0)
    st[g][p].clear();
  else
    st[g][p] = st[g][p-1];
  bef[x] = nbef[x];
  for (int i = p; i < (int)vs[g].size(); ++i)
    st[g][i].insert(make_pair(bef[vs[g][i].second], vs[g][i].second));
}

int Calc(int l, int r, int val) {
  if (r-l < 4 * S) {
    int ans = val + 1;
    for (int i = l; i < r; ++i) {
      if (a[i] > val) continue;
      if (bef[i] >= l) continue;
      --ans;
    }
    return ans;
  }
  int g = l / S;
  if (g * S < l)
    ++g;
  int cur = g * S;
  int ans = val + 1;
  for (int i = l; i < cur; ++i) {
    if (a[i] > val) continue;
    if (bef[i] >= l) continue;
    --ans;
  }
  pair<int, int> vpos(l, -1), vval(val+1, -1);
  for (int i = cur; i + S <= r; i += S, ++g) {
    int p = lower_bound(vs[g].begin(), vs[g].end(), vval) - vs[g].begin()-1;
    if (p < 0) continue;
    ans -= st[g][p].order_of_key(vpos);
  }
  for (int i = cur; i < r; ++i) {
    if (a[i] > val) continue;
    if (bef[i] >= l) continue;
    --ans;
  }
  return ans;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    bef[i] = -1;
    if (!pos[a[i]].empty())
      bef[i] = *pos[a[i]].rbegin();
    pos[a[i]].insert(i);
  }
  for (int i = 0; i < n; i += S) {
    int til = min(i+S, n);
    int g = i / S;
    vs[g].clear();
    for (int j = i; j < til; ++j) {
      vs[g].emplace_back(a[j], j);
    }
    sort(vs[g].begin(), vs[g].end());
    for (int j = 0; j < (int)vs[g].size(); ++j) {
      if (j)
        st[g][j] = st[g][j-1];
      int cur = vs[g][j].second;
      st[g][j].insert(make_pair(bef[cur], cur));
    }
  }
  cerr << " done " << endl;
  int ans = 0;
  int q;
  scanf("%d", &q);
  while (q--) {
#ifdef LOCAL
    ans = 0;
#endif
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int x, y;
      scanf("%d %d", &x, &y);
      x ^= ans;
      y ^= ans;
      --x, --y;
      if (a[x] == a[y]) continue;
      MovePos(a[x], x, y);
      MovePos(a[y], y, x);
      int ax = a[x], ay = a[y];
      SetVal(x, ay);
      SetVal(y, ax);
    }
    else {
      int l, r, k;
      scanf("%d %d %d", &l, &r, &k);
      l ^= ans;
      r ^= ans;
      k ^= ans;
      --l;
      int low = k-1, hig = r-l + k - 1;
      while (low < hig) {
        int mid = (low + hig) >> 1;
        int cnt = Calc(l, r, mid);
        if (cnt < k)
          low = mid + 1;
        else
          hig = mid;
      }
      ans = low;
      printf("%d\n", ans);
    }
  }
  return 0;
}
