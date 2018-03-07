#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

map<string, map<pair<int, int>, string> > mp;
vector<int> g[N];
vector<pair<string, string> > attr[N];
char s[N];
int st[N], en[N], cntr = 0;
void dfs(int v) {
  st[v] = cntr++;
  for (int u : g[v])
    dfs(u);
  en[v] = cntr;
}

void process(int v) {
  for (auto att : attr[v]) {
    auto & mpcur = mp[att.first];
    auto it = mpcur.lower_bound(make_pair(st[v]+1, 0));
    if (it != mpcur.begin()) {
      --it;
      if (it->first.first <= st[v] && en[v] <= it->first.second) {
        auto p = *it;
        mpcur.erase(it);
        auto p1 = make_pair(p.first.first, st[v]);
        auto p2 = make_pair(en[v], p.first.second);
        if (p1.first < p1.second)
          mpcur[p1] = p.second;
        if (p2.first < p2.second)
          mpcur[p2] = p.second;
      }
    }
    mpcur[make_pair(st[v], en[v])] = att.second;
  }
  for (int u : g[v])
    process(u);
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    int p, k;
    scanf("%d %d", &p, &k);
    if (p)
      g[p].push_back(i);
    while (k--) {
      scanf("%s", s);
      int len = strlen(s);
      for (int j = 0; j < len; ++j) {
        if (s[j] == '=') {
          attr[i].emplace_back(string(s, s+j), string(s+j+1, s+len));
          break;
        }
      }
    }
  }
  cntr = 0;
  dfs(1);
  process(1);
  int q;
  scanf("%d", &q);
  while (q--) {
    int c;
    scanf("%d %s", &c, s);
    string key = string(s);
    auto & mpcur = mp[key];
    auto it = mpcur.lower_bound(make_pair(st[c]+1, -1));
    if (it == mpcur.begin()) puts("N/A");
    else {
      --it;
      puts(it->first.first <= st[c] && st[c] < it->first.second ? it->second.c_str() : "N/A");
    }
    fflush(stdout);
  }
  return 0;
}