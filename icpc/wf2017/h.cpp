#include <bits/stdc++.h>

using namespace std;

const int N = 2e4 + 4;

pair<int, int> r[N];

int main() {
  int n, t;
  scanf("%d %d", &n, &t);
  vector<int> ending;
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    r[i] = {x, y};
    ending.push_back(y);
  }
  sort(r, r+n);
  sort(ending.begin(), ending.end());
  ending.erase(unique(ending.begin(), ending.end()), ending.end());
  vector<pair<int, int> > forbidden;
  for (int j = (int)ending.size() - 1; j >= 0; j--) {
    int cnt = 0;
    for (int i = n-1; i >= 0; --i) {
      if (r[i].first >= ending[j]) continue;
      if (r[i].second <= ending[j]) ++cnt;
      int c = ending[j] - cnt * t;
      if (c < r[i].first) {
        puts("no");
        return 0;
      }
      if (c-t+1 > r[i].first) continue;
      forbidden.emplace_back(c-t+1, r[i].first);
      cerr << c-t+1 << " forbidden " << r[i].first << " " << r[i].first << " " << ending[j] << endl;
    }
  }
  sort(forbidden.begin(), forbidden.end());
  set<pair<int, int> > st;
  int last = 0;
  int i = 0, j = 0;
  while (st.size() > 0 || i < n) {
    while (j < forbidden.size() && forbidden[j].first <= last) {
      last = max(last, forbidden[j].second); ++j;
    }
    while (i < n && r[i].first <= last) {
      st.insert(make_pair(r[i].second, i));
      cerr << " insert " << r[i].first << " "<< r[i].second << endl;
      ++i;
    }
    cerr << last << " " << i << " " << st.size() << endl;
    if (st.empty()) {
      last = max(r[i].first, last);
    }
    else {
      auto it = st.begin();
      cerr << " out " << it->first << endl; 
      if (it->first < last+t) {
        puts("no");
        return 0;
      }
      st.erase(it);
      last += t;
    }
  }
  puts("yes");
  return 0;
}