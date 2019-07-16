#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <bits/stdc++.h>

using namespace __gnu_pbds;
using namespace std;

const int N = 5e5 + 5;

typedef tree<
  int,
  null_type,
  less<int>,
  rb_tree_tag,
  tree_order_statistics_node_update>
  ordered_set;

int a[N];
int cnt[N];
long long k[N];
long long when_full[N];
int ans[N];

vector<int> ask[N];

int main() {
  int n, m, q;
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    ++cnt[a[i]];
  }
  for (int i = 0; i < q; ++i) {
    scanf("%lld", k+i);
  }
  vector<pair<int, int>> evs;
  for (int i = 1; i <= m; ++i)
    evs.emplace_back(cnt[i], i);
  sort(evs.begin(), evs.end());
  int city = 0;
  long long tot = n;
  for (int i = 0; i <= n; ++i) {
    tot += city;
    when_full[i] = tot;
    while (city < m && evs[city].first <= i) ++city;
  }
  // assert(city == m);
  for (int i = 0; i < q; ++i) {
    int pos = lower_bound(when_full, when_full+n+1, k[i]) - when_full;
    ask[pos].push_back(i);
  }
  ordered_set nodes;
  city = 0;
  for (int i = 1; i <= n+1; ++i) {
    while (city < m && evs[city].first < i) {
      nodes.insert(evs[city].second);
      ++city;
    }
    for (int id : ask[i]) {
      long long kurang = k[id] - when_full[i-1];
      // assert(kurang > 0);
      --kurang;
      kurang %= city;
      ans[id] = *nodes.find_by_order(kurang);
    }
  }
  for (int i = 0; i < q; ++i)
    printf("%d\n", ans[i]);
  return 0;
}
