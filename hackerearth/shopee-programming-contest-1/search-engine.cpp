#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

map<int, int> child[N];
map<string, int> names;
int nodes;
int last[N], cnts[N];

int get_id(string s) {
  auto it = names.find(s);
  if (it != names.end())
    return it->second;
  int now = names.size();
  return names[s] = now;
}

int go(int now, int x) {
  auto it = child[now].find(x);
  if (it != child[now].end())
    return it->second;
  return child[now][x] = nodes++;
}

void solve() {
  nodes = 1;
  names.clear();
  int n, q;
  scanf("%d %d\n", &n, &q);
  int root = 0;
  fill(last, last+N, -1);
  fill(cnts, cnts+N, 0);
  for (int i = 0; i < n; ++i) {
    string s;
    getline(cin, s);
    string cur = "";
    vector<int> seqs;
    for (char c : s) {
      if (c == ' ') {
        if (cur.size() > 0)
          seqs.push_back(get_id(cur));
        cur = "";
      } else {
        cur.push_back(c);
      }
    }
    if (cur.size() > 0)
      seqs.push_back(get_id(cur));
    for (int j = 0; j < (int)seqs.size(); ++j) {
      int now = root;
      for (int k = j; k < (int)seqs.size(); ++k) {
        now = go(now, seqs[k]);
        if (last[now] < i) {
          ++cnts[now];
          last[now] = i;
        }
      }
    }
  }
  for (int i = 0; i < q; ++i) {
    string s;
    getline(cin, s);
    string cur = "";
    vector<int> seqs;
    for (char c : s) {
      if (c == ' ') {
        if (cur.size() > 0)
          seqs.push_back(get_id(cur));
        cur = "";
      } else {
        cur.push_back(c);
      }
    }
    if (cur.size() > 0)
      seqs.push_back(get_id(cur));
    int now = root;
    for (int x : seqs) {
      now = go(now, x);
      if (cnts[now] == 0)
        break;
    }
    printf("%d\n", cnts[now]);
  }
  for (int i = 0; i <= nodes; ++i)
    child[i].clear();
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tc = 1; tc <= t; ++tc) {
    printf("Case %d:\n", tc);
    solve();
  }
  return 0;
}
