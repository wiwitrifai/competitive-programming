#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], b[N];

vector<int> pos[N];

void solve() {
  int n, x, y;
  scanf("%d %d %d", &n, &x, &y);
  int low = y - x, hig = n - x;
  for (int i = 0; i <= n+1; ++i)
    pos[i].clear();
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    b[i] = a[i];
    pos[a[i]].push_back(i);
  }
  int notexist = -1;
  for (int i = 1; i <= n+1; ++i) {
    if (pos[i].empty()) {
      notexist = i;
      break;
    }
  }
  set<pair<int, int>> st;
  for (int i = 0; i <= n+1; ++i) {
    if (pos[i].size() > 0) {
      st.insert({-(int)pos[i].size(), i});
    }
  }
  int swapped = 0;
  while (swapped < low && st.size() > 1) {
    auto it = st.begin();
    auto it2 = it++;
    int u = it->second, v = it2->second;
    st.erase(it);
    st.erase(it2);
    swap(b[pos[u].back()], b[pos[v].back()]);
    if ((low - swapped) == 3 && st.size() > 0) {
      it = st.begin();
      int w = it->second;
      st.erase(it);
      swap(b[pos[u].back()], b[pos[w].back()]);
      pos[w].pop_back();
      if (pos[w].size() > 0) {
        st.insert({-(int)pos[w].size(), w});
      }
      ++swapped;
    }
    pos[u].pop_back();
    pos[v].pop_back();
    if (pos[u].size() > 0)
      st.insert({-(int)pos[u].size(), u});
    if (pos[v].size() > 0) {
      st.insert({-(int)pos[v].size(), v});
    }
    swapped += 2;
  }
  if (swapped < low || swapped > hig) {
    puts("NO");
    return;
  }
  puts("YES");
  int diff = swapped - low, same = hig - swapped;
  for (int i = 0; i < n; ++i) {
    if (a[i] == b[i]) {
      if (same > 0) {
        b[i] = notexist;
        --same;
      }
    } else {
      if (diff > 0) {
        b[i] = notexist;
        --diff;
      }
    }
  }
  assert(same == 0 && diff == 0);
  for (int i = 0; i < n; ++i)
    printf("%d%c", b[i], i+1 == n ? '\n' : ' ');
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
