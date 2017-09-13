#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

string s[N];
char c[N];
map<string, int> mp;
int n;
pair<int, int > parse(string str) {
  int k = str.size();
  string pre = str.substr(0, k-1), suf = str.substr(1, k-1);
  int le = -1, ri = -1;
  map<string, int>::iterator it = mp.find(pre);
  if (it == mp.end())
    s[n] = pre, mp[pre] = le = n++;
  else
    le = it->second;
  it = mp.find(suf);
  if (it == mp.end())
    s[n] = suf, mp[suf] = ri = n++;
  else
    ri = it->second;
  return make_pair(le, ri);
}

vector<int> g[N], ans;
int din[N], p[N];

void dfs(int v) {
  for (; p[v] < g[v].size();) {
    int u = g[v][p[v]++];
    dfs(u);
  }
  ans.push_back(v);
}

int main() {
  int m, k;
  scanf("%d %d", &m, &k);
  if (k == 1) {
    for (int i = 0; i < m; i++) {
      scanf("%s", c);
      printf("%s", c);
    }
    printf("\n");
    return 0;
  }
  n = 0;
  for (int i = 0; i < m; i++) {
    scanf("%s", c);
    pair<int, int> uv = parse(string(c));
    g[uv.first].push_back(uv.second);
    din[uv.second]++;
  }
  memset(p, 0, sizeof p);
  int st = 0;
  int up = 0, down = 0, same = 0;
  for (int i = 0; i < n; i++) {
    if (din[i] == g[i].size())
      continue;
    if (din[i] + 1 == g[i].size())
      st = i, up++;
    else if (din[i] == g[i].size() + 1)
      down++;
    else {
      puts("-1");
      return 0;
    }
  }
  if (up > 1 || down > 1 || up != down) {
    puts("-1");
    return 0;
  }

  dfs(st);
  if (ans.size() != m+1)
    puts("-1");
  else {
    reverse(ans.begin(), ans.end());
    printf("%s", s[ans[0]].c_str());
    for (int i = 1; i < ans.size(); i++) {
      printf("%c", s[ans[i]][k-2]);
    }
    printf("\n");
  }
  return 0;
}