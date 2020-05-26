#include <bits/stdc++.h>

using namespace std;

vector<int> calc(vector<int> & p) {
  vector<int> a;
  set<int> sum;
  sum.insert(0);
  int id = 0;
  while (true) {
    int found = -1;
    for (; id < (int)p.size(); ++id) {
      int i = p[id];
      if (sum.count(i)) continue;
      bool ok = 1;
      int cur = i;
      for (int j = (int)a.size()-1; j >= 0; --j) {
        cur += a[j];
        if (sum.count(cur)) {
          ok = 0;
          break;
        }
      }
      if (ok) {
        found = i;
        break;
      }
    }
    if (found == -1) break;
    a.push_back(found);
    int cur = 0;
    for (int j = (int)a.size()-1; j >= 0; --j) {
      cur += a[j];
      assert(!sum.count(cur));
      sum.insert(cur);
    }
  }
  return a;
}

int main() {
  int n;
  cin >> n;
  vector<int> p(n);
  iota(p.begin(), p.end(), 1);
  vector<vector<vector<int>>> res;
  res.resize(p.size()+1);
  do {
    vector<int> cur = calc(p);
    res[cur.size()].push_back(cur);
  } while (next_permutation(p.begin(), p.end()));
  for (int i = (int)res.size()-1; i >= 0; --i) {
    if (res[i].empty()) continue;
    sort(res[i].begin(), res[i].end());
    res[i].erase(unique(res[i].begin(), res[i].end()), res[i].end());
    cerr << " longest " << i << " " << res[i].size() << endl;
    for (auto & v : res[i]) {
      for (int x : v)
        cout << x << " ";
      cout << endl;
    }
    break;
  }
  return 0;
}
