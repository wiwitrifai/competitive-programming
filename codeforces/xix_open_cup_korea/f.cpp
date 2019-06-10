#include <bits/stdc++.h>

using namespace std;

set<long long> st;

void rec(long long n) {
  if (n <= 1)
    return;
  if (st.count(n))
    return;
  st.insert(n);
  long long half = n/2;
  rec(half);
  rec(n-half);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    st.clear();
    st.insert(1);
    long long n;
    scanf("%lld", &n);
    rec(n);
    map<long long, int> mp;
    vector<pair<int, int> > ans;
    ans.emplace_back(-1, -1);
    mp[1] = 0;
    for (long long x : st) {
      if (x <= 1) continue;
      long long half = x / 2;
      mp[x] = (int)ans.size();
      ans.emplace_back(mp[x - half], mp[half]);
    }
    printf("%d\n", (int)ans.size());
    for (auto it : ans) {
      printf("%d %d\n", it.first, it.second);
    }
    printf("%d\n", (int)ans.size() - 1);
  }

  return 0;
}
