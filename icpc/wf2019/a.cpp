#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector<pair<int, int> > back(n), front(n);
  vector<int> id1(n), id2(n);
  iota(id1.begin(), id1.end(), 0);
  iota(id2.begin(), id2.end(), 0);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &back[i].first);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &back[i].second);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &front[i].first);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &front[i].second);
  }
  sort(id1.begin(), id1.end(), [&back](int l, int r) { return back[l] < back[r]; });
  sort(id2.begin(), id2.end(), [&front](int l, int r) { return front[l] < front[r]; });
  multiset<pair<int, int> > st_back, st_front;
  vector<pair<int, int>> ans;
  int i = 0, j = 0;
  while (i < n || !st_back.empty()) {
    if (st_front.empty()) {
      int v = front[id2[j]].first;
      while (j < n && front[id2[j]].first == v) {
        st_front.insert(make_pair(front[id2[j]].second, id2[j]));
        ++j;
      }
    }
    if (st_back.empty()) {
      int v = back[id1[i]].first;
      while (i < n && back[id1[i]].first == v) {
        st_back.insert(make_pair(back[id1[i]].second, id1[i]));
        ++i;
      }
    }
    assert(!st_front.empty() && !st_back.empty());
    if (st_back.size() <= st_front.size()) {
      auto it1 = st_back.begin();
      auto it2 = st_front.lower_bound(make_pair(it1->first, -1));
      if (it2 == st_front.begin()) {
        puts("impossible");
        return 0;
      }
      --it2;
      assert(it1->first > it2->first);
      ans.emplace_back(it1->second + 1, it2->second + 1);
      st_back.erase(it1);
      st_front.erase(it2);
    }
    else {
      auto it2 = st_front.begin();;
      auto it1 = st_back.lower_bound(make_pair(it2->first+1, -1));
      if (it1 == st_back.end()) {
        puts("impossible");
        return 0;
      }
      assert(it1->first > it2->first);
      ans.emplace_back(it1->second + 1, it2->second + 1);
      st_back.erase(it1);
      st_front.erase(it2);
    }
  }
  for (int i = 0; i < n; ++i)
    printf("%d%c", ans[i].first, i == n-1 ? '\n' : ' ');
  for (int i = 0; i < n; ++i)
    printf("%d%c", ans[i].second, i == n-1 ? '\n' : ' ');
  return 0;
}
