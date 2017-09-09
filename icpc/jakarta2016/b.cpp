/**
 *  ACM ICPC Regional Jakarta 2016 - B : Confusing Manuscript
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 4;

char s[N][15];
int cnt[N];
vector< pair<string, int> > vs;
map<string, int> mp;

int main() {
  int t;
  scanf("%d", &t);
  for (int tc = 1; tc <= t; tc++) {
    int n;
    scanf("%d", &n);
    vs.clear();
    mp.clear();
    for (int i = 0; i < n; i++) {
      scanf("%s", s+i);
      string cur = string(s[i]);
      mp[cur] = i;
      cnt[i] = 0;
    }
    for (int i = 0; i < n; i++) {
      string cur = string(s[i]);
      set<int> st;
      for (int j = 0; j < cur.size(); j++) {
        cur[j] = '?';
        vs.emplace_back(cur, i);
        cur[j] = s[i][j];
        string d = cur.substr(0, j) + cur.substr(j+1);
        auto it = mp.find(d);
        if (it != mp.end()) {
          st.insert(it->second);
        }
      }
      cnt[i] += st.size();
      for (int u : st)
        cnt[u]++;
    }
    sort(vs.begin(), vs.end());
    for (int i = 0; i < vs.size();) {
      int l = i;
      while (i < vs.size() && vs[l].first == vs[i].first) i++;
      for (int j = l; j < i; j++)
        cnt[vs[j].second] += i-l-1;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
      if (cnt[ans] < cnt[i])
        ans = i;
    printf("Case #%d: %s\n", tc, s[ans]);
  }
  return 0;
}