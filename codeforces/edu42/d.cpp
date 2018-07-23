#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

long long a[N];

int main() {
  int n;
  scanf("%d", &n);
  set<pair<long long, int> > st;
  for (int i = 0; i < n; ++i)
    scanf("%lld", a+i), st.insert(make_pair(a[i], i));
  while (st.size() > 1) {
    auto it = st.begin();
    int l = it->second; st.erase(it);
    it = st.begin();
    if (a[l] == it->first) {
      int r = it->second;
      st.erase(it);
      a[r] += a[l];
      a[l] = -1;
      st.insert(make_pair(a[r], r));
    }
  }
  vector<long long> ans;
  for (int i = 0; i < n; ++i)
    if (a[i] != -1)
      ans.push_back(a[i]);
  printf("%d\n", (int)ans.size());
  for (int i = 0; i < ans.size(); ++i) {
    if (i) printf(" ");
    printf("%lld", ans[i]);
  }
  printf("\n");
  return 0;
}