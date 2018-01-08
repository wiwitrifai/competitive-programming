#include <bits/stdc++.h>

using namespace std;

const int N = 1 << 8;

string dp[N][3];
bool vis[N][3];
set<int> st[3];
string compare(string a, string b) {
  if (a.empty()) return b;
  if (b.empty()) return a;
  if (a.size() != b.size()) {
    if (a.size() < b.size())
      return a;
    else
      return b;
  }
  else {
    if (a < b)
      return a;
    else
      return b;
  }
}

string solve(int mask, int id) {
  return dp[mask][id];
}
set<pair<pair<int, string>, pair<int, int> > > pq;
void upd(int mask, int id, string val) {
  string best = compare(val, dp[mask][id]);
  if (best != dp[mask][id]) {
    pq.erase(make_pair(make_pair(dp[mask][id].size(), dp[mask][id]), make_pair(mask, id)));
    dp[mask][id] = best;
    pq.insert(make_pair(make_pair(dp[mask][id].size(), dp[mask][id]), make_pair(mask, id)));
  }
}

char s[1231];
int main() {
  memset(vis, 0, sizeof vis);
  for (int i = 0; i< N; ++i)
    for (int j = 0; j < 3; ++j)
      dp[i][j] = "";
  int x = 0, y = 0, z = 0;
  for (int i = 0; i < 8; ++i) {
    if (i & 4) x |= 1 << i;
    if (i & 2) y |= 1 << i;
    if (i & 1) z |= 1 << i;
  }
  dp[x][2] = "x";
  dp[y][2] = "y";
  dp[z][2] = "z";
  vis[z][2] = vis[x][2] = vis[y][2] = 1;
  st[2].insert(x);
  st[2].insert(y);
  st[2].insert(z);
  pq.insert(make_pair(make_pair(1, dp[x][2]), make_pair(x, 2)));
  pq.insert(make_pair(make_pair(1, dp[y][2]), make_pair(y, 2)));
  pq.insert(make_pair(make_pair(1, dp[z][2]), make_pair(z, 2)));
  while (!pq.empty()) {
    auto it = pq.begin();
    int mask = it->second.first, id = it->second.second;
    pq.erase(it);
    vis[mask][id] = 1;
    st[id].insert(mask);
    if (id == 0) {
      for (int ot : st[1]) {
        upd(mask | ot, 0, dp[mask][0] + "|" + dp[ot][1]);
      }
      upd(mask, 2, "(" + dp[mask][0] + ")");
    }
    else if (id == 1) {
      upd(mask, 0, dp[mask][1]);
      for (int ot : st[0])
        upd(ot | mask, 0, dp[ot][0] + "|" + dp[mask][1]);
      for (int ot : st[2])
        upd(ot & mask, 1, dp[mask][1] + "&" + dp[ot][2]);
    }
    else {
      upd(mask, 1, dp[mask][2]);
      for (int ot : st[1])
        upd(ot & mask, 1, dp[ot][1] + "&" + dp[mask][2]);
      upd(mask ^ (N-1), 2, "!"+dp[mask][2]);
    }
  }
  int tot = 0;
  for (int i = 0; i < N; ++i) {
    string ans;
    for (int j = 0; j < 3; ++j)
      ans =compare(ans, solve(i, j));
    tot = max(tot, (int)ans.size());
  }
  cerr << tot << endl;
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", s);
    int mask = 0;
    for (int i = 0; i < 8; ++i)
      if (s[i] == '1')
        mask |= 1 << i;
    string ans;
    for (int i = 0; i < 3; ++i) {
      solve(mask, i);
      ans = compare(ans, solve(mask, i));
    }
    printf("%s\n", ans.c_str());
  }
  return 0;
}