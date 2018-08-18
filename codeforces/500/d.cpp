#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int> > ans;

void add(int u, int v, bool rev) {
  if (rev)
    swap(u, v);
  ans.emplace_back(u, v);
}

void swap(string & a, int pa, string & b, int pb) {
  string ta = b.substr(0, pb) + a.substr(pa, (int)a.size() - pa);
  string tb = a.substr(0, pa) + b.substr(pb, (int)b.size() - pb);
  a = ta;
  b = tb;
}

void solve3(string a, string b, bool rev) {
  cerr << " solve3 " << a << " " << b << endl;
  assert(a.back() != b.back());
  int cnt = 0;
  vector<int> va, vb;
  for (int i = 1; i < a.size(); ++i) {
    if (a[i] == a[i-1]) continue;
    va.push_back(i);
  }
  for (int i = 1; i < b.size(); ++i) {
    if (b[i] == b[i-1]) continue;
    vb.push_back(i);
  }
  assert(va.size() == vb.size());
  reverse(va.begin(), va.end());
  reverse(vb.begin(), vb.end());
  // cerr << a << " " << b << endl;
  if (va.size() & 1)
    rev = !rev;
  for (int i = 0; i < va.size(); ++i) {
    add(va[i], vb[i], rev);
    rev = !rev;
  }
}

void solve2(string a, string b, bool rev) {
  vector<int> va, vb;
  for (int i = 1; i < a.size(); ++i) {
    if (a[i] == a[i-1]) continue;
    va.push_back(i);
  }
  for (int i = 1; i < b.size(); ++i) {
    if (b[i] == b[i-1]) continue;
    vb.push_back(i);
  }
  if (va.size() > vb.size()) {
    va.swap(vb);
    swap(a, b);
    rev = !rev;
  }
  if (va.size() < vb.size()) {
    assert(vb.size() == va.size() + 1);
    swap(a, 0, b, vb[0]);
    add(0, vb[0], rev);
  }
  solve3(a, b, rev);
}

void solve1(string a, string b, bool rev) {
  cerr << " solve1 " << a << " " << b << endl;
  assert(a.back() != b.back());
  vector<int> va, vb;
  for (int i = 1; i < a.size(); ++i) {
    if (a[i] == a[i-1]) continue;
    va.push_back(i);
  }
  for (int i = 1; i < b.size(); ++i) {
    if (b[i] == b[i-1]) continue;
    vb.push_back(i);
  }
  if (va.size() != vb.size()) {
    if (va.size() > vb.size()) {
      va.swap(vb);
      swap(a, b);
      rev = !rev;
    }
    if (va.size() == 0) {
      int bagi = ((int)vb.size())/2;
      if (b[vb[bagi]] == a.back()) ++bagi;
      while (bagi >= vb.size()) bagi -= 2;
      bagi = max(bagi, 0);
      swap(a, 0, b, vb[bagi]);
      add(0, vb[bagi], rev);
    }
    else {
      int pa = -1, pb = -1;
      int beda = vb.size() - va.size();
      for (int i = 0; i < va.size() && i < 2; ++i) {
        int cur = beda;
        int j = 0;
        if (b[vb[j]] == a[va[i]]) {
          ++j;
          cur -= 2;
        }
        while (cur > 1 && j + 2 < vb.size()) {
          j += 2;
          cur -= 4;
        }
        if (abs(cur) <= 1) {
          pa = va[i];
          pb = vb[j];
          break;
        }
        cur -= 2;
      }
      if (pa == -1) {
        int bagi = ((int)vb.size())/2;
        if (b[vb[bagi]] == a.back()) ++bagi;
        while (bagi >= vb.size()) bagi -= 2;
        bagi = max(bagi, 0);
        pa = 0;
        pb = vb[bagi];
      }
      swap(a, pa, b, pb);
      add(pa, pb, rev);
    }
  }
  solve2(a, b, rev);
}

void solve(string a, string b) {
  cerr << " solve " << a << " " << b << endl;
  bool rev = 0;
  if (a.back() == b.back()) {
    vector<int> va, vb;
    for (int i = 1; i < a.size(); ++i) {
      if (a[i] == a[i-1]) continue;
      va.push_back(i);
    }
    for (int i = 1; i < b.size(); ++i) {
      if (b[i] == b[i-1]) continue;
      vb.push_back(i);
    }
    if (va.size() > vb.size()) {
      va.swap(vb);
      swap(a, b);
      rev = !rev;
    }
    assert(vb.size() > 0);
    int u = a.size(), v = min(2, (int)vb.size()-1);
    if (b[vb[v]] != a.back())
      ++v;
    if (v >= vb.size()) v -= 2;
    v = vb[v];
    swap(a, u, b, v);
    add(u, v, rev);
  }
  solve1(a, b, rev);
}

int main() {
  string a, b;
  cin >> a >> b;
  solve(a, b);
  printf("%d\n", (int)ans.size());
  // cerr << a << " " << b << endl;
  for (auto it : ans) {
    printf("%d %d\n", it.first, it.second);
    swap(a, it.first, b, it.second);
    // cerr << a << " " << b << endl;
  }
  return 0;
}