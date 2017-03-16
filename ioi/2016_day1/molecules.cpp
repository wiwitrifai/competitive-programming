#include <bits/stdc++.h>

using namespace std;

std::vector<int> find_subset(int l, int u, std::vector<int> w) {
  int n = w.size();
  vector< pair< int, int > > val(n);
  vector< bool > used(n, 0);
  for (int i = 0; i < n; i++) 
    val[i] = make_pair(w[i], i);
  sort(val.begin(), val.end());
  vector < int > ans;
  long long sum = 0;
  for (int i = n-1; i >= 0; i--) {
    if (sum >= l)
      break;
    sum += val[i].first;
    ans.push_back(val[i].second);
    used[val[i].second] = 1;
  }
  if (sum <= u && sum >= l)
    return ans;
  if (sum < l)
    return vector<int>(0);
  long long tmp = 0;
  for (int i = 0; i < ans.size(); i++)
    tmp += val[i].first;
  if (tmp > u)
    return vector<int>(0);
  for (int i = 0; i < ans.size(); i++) {
    sum -= (w[ans[i]] - val[i].first);
    ans[i] = val[i].second;
    if (sum <= u)
      break;
  }
  assert(sum >= l);
  sort(ans.begin(), ans.end());
  return ans;
}
