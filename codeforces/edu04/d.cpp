#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int n, k, val[N<<1], cnt[N<<1];
pair< int, int > seg[N];
vector< int > co;
vector< pair< int, int > > ans;

int main() {
  scanf("%d%d", &n, &k);
  for(int i = 0; i<n; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    seg[i] = make_pair(l, r);
    co.push_back(l);
    co.push_back(r);
  }
  sort(co.begin(), co.end());
  co.erase(unique(co.begin(), co.end()), co.end());
  for(int i = 0; i<n; i++) {
    int l = lower_bound(co.begin(), co.end(), seg[i].first)-co.begin();
    int r = lower_bound(co.begin(), co.end(), seg[i].second)-co.begin();
    val[l]++;
    val[r]--;
    cnt[r]++;
  }
  int last = -1;
  for(int i = 0; i< co.size(); i++) {
    val[i+1] += val[i];
    if(last >= 0) {
      if(val[i] < k) {
        ans.emplace_back(co[last], co[i]);
        last = -1;
      }
    }
    else {
      if(val[i] >= k)
        last = i;
      if(val[i] < k && (val[i] + cnt[i]) >= k)
        ans.emplace_back(co[i], co[i]);
    }
  }
  if(last >= 0) {
    ans.emplace_back(co[last], co.back());
  }
  printf("%d\n", ans.size());
  for(int i = 0; i<ans.size(); i++)
    printf("%d %d\n", ans[i].first, ans[i].second);
  return 0;
}