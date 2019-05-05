#include <bits/stdc++.h>

using namespace std;

const int N = 4, K = 10;

map<vector<int>, int> grund;
vector<int> vmask;

set<int> st;

vector<int> now;
void find(int n, int cnt = 0) {
  if (cnt > K/2) return;
  if (n == K) {
    if (cnt != K/2) return;
    auto it = grund.find(now);
    assert(it != grund.end());
    st.insert(it->second);
    return;
  }
  for (int i = 0; i <= now[n]; ++i) {
    now[n] -= i;
    find(n+1, cnt + (i != 0));
    now[n] += i;
  }
}

void dfs(int n) {
  if (n == K) {
    st.clear();
    find(0);
    int res = 0;
    for (int x : st)
      res += res == x;
    grund[now] = res;
    if (res == 0) {
      bool ok = 1;
      for (int i = 0; i+1 < n; ++i) {
        if (now[i] > now[i+1])
          ok = 0;
      }
      if (!ok)
        return;
      for (int i = 0; i < n; ++i)
        cerr << now[i] << " ";
      cerr << " = " << res << endl;
    }
    return;
  }
  for (int i = 0; i < N; ++i) {
    now.push_back(i);
    dfs(n+1);
    now.pop_back();
  }
}

int main() {
  dfs(0);
  return 0;
}
