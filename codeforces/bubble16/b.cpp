#include <bits/stdc++.h>

using namespace std;

set < pair<long long, int > > st;

int n;
long long c0, c1;

int main() {
  cin >> n >> c0 >> c1;
  long long ans = 0;
  int now = 2;
  st.insert(make_pair(c0, 0));
  st.insert(make_pair(c1, 1));
  ans = c0 + c1;
  while (true) {
    if (st.size() < n) {
      auto it = st.begin();
      long long cur = it->first;
      st.erase(it);
      st.insert(make_pair(cur + c0, now++));
      st.insert(make_pair(cur + c1, now++));
      ans += cur + c0 + c1;
    }
    else {
      auto it = st.begin();
      long long cur = it->first;
      st.erase(it);
      auto ed = --st.end();
      if (cur + c0 + c1 >= ed->first)
        break;
      ans += cur + c0 + c1 - ed->first;
      st.erase(ed);
      st.erase(it);
      st.insert(make_pair(cur + c0, now++));
      st.insert(make_pair(cur + c1, now++));
    }
  }
  cout << ans << endl;

  return 0;
}