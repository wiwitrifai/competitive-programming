#include <bits/stdc++.h>

using namespace std;

const int N = 303;

map<string, int> mp;
int nodes = 0;

int id(string s) {
  auto it = mp.find(s);
  if (it == mp.end()) {
    mp[s] = nodes++;
    it = mp.find(s);
  }
  return it->second;
}

map<pair<int, int>, int> cost;
char s[100];

int main() {
  int n, a, b, f, k;
  scanf("%d %d %d %d %d", &n, &a, &b, &k, &f);
  int last = -1;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int u, v;
    scanf("%s", s);
    u = id(string(s));
    scanf("%s", s);
    v = id(string(s));
    int pay = a;
    if (last == u)
      pay = b;
    last = v;
    if (u > v)
      swap(u, v);
    ans += pay;
    cost[make_pair(u, v)] += pay;
  }
  vector<int> pays;
  for (auto it : cost)
    pays.push_back(it.second);
  sort(pays.begin(), pays.end());
  reverse(pays.begin(), pays.end());
  for (int val : pays) {
    if (k) {
      k--;
      ans -= max(0, val-f);
    }
  }
  cout << ans << endl;
  return 0;
}