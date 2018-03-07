#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

queue<int> que[N];

pair<int, int> ans[N];

int main() {
  int n, k;
  scanf("%d %d", &k, &n);
  int s = k/n;
  for (int i = 0; i < k; ++i) {
    int c;
    scanf("%d", &c);
    if (c == -1)
      que[0].push(i);
    else
      que[c].push(i);
  }
  set<pair<int, int> > st;
  for (int i = 1; i <= n; ++i) {
    st.insert(make_pair(que[i].size(), i));
  }
  while (!st.empty()) {
    auto it = st.begin();
    int id = it->second; st.erase(it);
    int a = id;
    for (int j = 1; j <= n; ++j) {
      if (j == a) continue;
      if (a == id || que[j].size() > que[a].size())
        a = j;
    }
    int hapus = s;
    while (hapus && que[id].size()) {
      int x = que[id].front(); que[id].pop();
      ans[x] = {id, a};
      --hapus;
    }
    st.erase(make_pair(que[a].size(), a));
    while (hapus && que[a].size()) {
      int x = que[a].front(); que[a].pop();
      ans[x] = {id, a};
      --hapus;
    }
    if (que[a].size() > 0)
      st.insert(make_pair(que[a].size(), a));
    while (hapus && que[0].size()) {
      int x = que[0].front(); que[0].pop();
      ans[x] = {id, a};
      --hapus;
    }
  }
  while (que[0].size()) {
    int x = que[0].front(); que[0].pop();
    ans[x] = {1, 1};
  }
  puts("Yes");
  for (int i = 0; i < k; ++i)
    printf("%d %d\n", ans[i].first, ans[i].second);
  return 0;
}