#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

vector<pair<int, int> > upd;
int val[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  set<pair<int, int> > st;
  for (int i = 0; i < n; ++i) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    val[i] = a + b + c;
    upd.emplace_back(k-a, i);
    upd.emplace_back(k-b, i);
    upd.emplace_back(k-c, i);
    st.insert(make_pair(val[i], i));
  }
  int last = 0;
  int ans = st.rbegin()->first;
  sort(upd.begin(), upd.end());
  for (auto it : upd) {
    if (it.first != last)
      ans = min(ans, st.rbegin()->first + 3 * last);
    int x = it.second;
    st.erase(make_pair(val[x], x));
    val[x] -= k;
    st.insert(make_pair(val[x], x));
    last = it.first;
  }
  ans = min(ans, st.rbegin()->first + 3 * last);
  printf("%d\n", ans);
  return 0;
}