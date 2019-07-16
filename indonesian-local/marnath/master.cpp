#include <bits/stdc++.h>

using namespace std;

int to[25 * 100][256], newnode = 1;
vector< int > num[25 * 100];

string toLower(string s) {
  for (int i = 0; i < s.size(); i++) {
    if (s[i] >= 'A' && s[i] <= 'Z') {
      s[i] = s[i] - 'A' + 'a';
    }
  }
  return s;
}
int cnt[100000], lim;
string base;
set< pair<pair<int, int >, int> > st;

void dfs(int id, int pos, int le, int ri, int depth = 0) {
  if (depth > 10) return;
  if (pos < 0 || pos >= base.size()) return;
  if (cnt[pos] >= lim) return;
  id = to[id][base[pos]];
  if (id == 0) return;
  cnt[pos]++;
  le = min(le, pos);
  ri = max(ri, pos);
  if (num[id].size()) {
    for (int i = 0; i < num[id].size(); i++)
      st.insert(make_pair(make_pair(le, ri), num[id][i]));
    return;
  }
  dfs(id, pos-1, le, ri, depth+1);
  dfs(id, pos+1, le, ri, depth+1);
  cnt[pos]--;
}

int solve(int k) {
  lim = k;
  st.clear();
  for (int i = 0; i < base.size(); i++) {
    dfs(1, i, i, i);
  }
  return st.size();
}

int trie() {
  memset(to[newnode], 0, sizeof to[newnode]);
  num[newnode].clear();
  return newnode++;
}

void add(string s, int val) {
  int now = 1;
  for (int i = 0; i < s.size(); i++) {
    int c = s[i];
    if (!to[now][c])
      to[now][c] = trie();
    now = to[now][c];
  }
  num[now].push_back(val);
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tc = 1; tc <= t; tc++) {
    string s;
    base = "";
    while (getline(cin, s) && s != "--") {
      base += toLower(s) + "\n";
    }
    int n, k;
    scanf("%d %d", &n, &k);
    newnode = 1;
    trie();
    for (int i = 0; i < n; i++) {
      cin >> s;
      s = toLower(s);
      add(s, i);
    }
    int ans = solve(k);
    printf("Case %d: %d\n", tc, ans);
  }
  return 0;
}