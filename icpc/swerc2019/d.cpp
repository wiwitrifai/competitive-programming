#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 4;

int lef[N+N+N], rig[N+N+N];
int nodes = N;

map<pair<int, int>, int> memo;

int merge(int u, int v) {
  pair<int, int> now = make_pair(u, v);
  auto it = memo.find(now);
  if (it != memo.end())
    return it->second;
  ++nodes;
  lef[nodes] = u;
  rig[nodes] = v;
  return memo[now] = nodes;
}

vector<int> process(string s) {
  vector<int> ret(N);
  iota(ret.begin(), ret.end(), 1);
  reverse(ret.begin(), ret.end());
  for (char c : s) {
    int now, le, ri;
    switch (c) {
      case 'C':
        ret.push_back(ret.back());
        break;
      case 'D':
        ret.pop_back();
        break;
      case 'L':
        now = ret.back();
        if (!lef[now] || !rig[now])
          return vector<int>();
        ret.back() = lef[now];
        break;
      case 'P':
        le = ret.back(); ret.pop_back();
        ri = ret.back();
        ret.back() = merge(le, ri);
        break;
      case 'R':
        now = ret.back();
        if (!lef[now] || !rig[now])
          return vector<int>();
        ret.back() = rig[now];
        break;
      case 'S':
        swap(ret.back(), ret[(int)ret.size()-2]);
        break;
      case 'U':
        now = ret.back();
        if (!lef[now] || !rig[now])
          return vector<int>();
        ret.back() = rig[now];
        ret.push_back(lef[now]);
        break;
      default:
        assert(false);    
    }
  }
  return ret;
}

int main() {
  string a, b;
  cin >> a >> b;
  vector<int> resa = process(a), resb = process(b);
  puts(resa == resb ? "True" : "False");
  return 0;
}
