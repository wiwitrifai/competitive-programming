#include <bits/stdc++.h>

using namespace std;

set < pair<int, int> > st;

const int N = 205;

int d[N], s[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", s+i, d+i);
    auto it1 = st.lower_bound(make_pair(s[i], 0));
    if (it1 == st.end() || (it1->first >= s[i] + d[i] && !it1->second)) {
      printf("%d %d\n", s[i], s[i] + d[i] - 1);
      st.insert({s[i], 0});
      st.insert({s[i] + d[i] - 1, 1});
      continue;
    }
    it1 = st.lower_bound(make_pair(1, 0));
    if (it1->first > d[i]) {
      printf("%d %d\n", 1, d[i]);
      st.insert({1, 0});
      st.insert({d[i], 1});
      continue;
    }
    for (auto it = st.begin(); it != st.end();) {
      it++;
      int now = it->first + 1;
      it++;
      if (it == st.end() || now + d[i] <= it->first) {
        printf("%d %d\n", now, now+d[i]-1);
        st.insert({now, 0});
        st.insert({now+d[i]-1, 1});
        break;
      }
    }
  }
  return 0;
}