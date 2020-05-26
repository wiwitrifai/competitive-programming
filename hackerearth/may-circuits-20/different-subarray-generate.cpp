#include <bits/stdc++.h>

using namespace std;

const int A = 3e4;


vector<int> calc(vector<int> & p) {
  set<int> sum;
  sum.insert(0);
  int id = 0;
  vector<int> a(p.size() * 3, 0);
  int l = a.size()/2, r = l-1;
  auto addR = [&](int i) {
    if (sum.count(i)) return false;
    int cur = i;
    for (int j = r; j >= l; --j) {
      cur += a[j];
      if (sum.count(cur)) {
        return false;
      }
    }
    a[++r] = i;
    cur = 0;
    for (int j = r; j >= l; --j) {
      cur += a[j];
      assert(!sum.count(cur));
      sum.insert(cur);
    }
    return true;
  };
  auto addL = [&](int i) {
    if (sum.count(i)) return false;
    int cur = i;
    for (int j = l; j <= r; ++j) {
      cur += a[j];
      if (sum.count(cur)) {
        return false;
      }
    }
    a[--l] = i;
    cur = 0;
    for (int j = l; j <= r; ++j) {
      cur += a[j];
      assert(!sum.count(cur));
      sum.insert(cur);
    }
    return true;
  };
  auto costL = [&](int i) {
    if (sum.count(i)) return -1LL;
    int cur = i;
    for (int j = l; j <= r; ++j) {
      cur += a[j];
      if (sum.count(cur)) {
        return -1LL;
      }
    }
    a[l-1] = i;
    cur = 0;
    long long ret = 0;
    for (int j = l-1; j <= r; ++j) {
      cur += a[j];
      auto it = sum.lower_bound(cur);
      assert(it == sum.end() || *it != cur);
      int dif = 1e9;
      if (it != sum.end())
        dif = min(dif, abs(*it - cur));
      if (it != sum.begin()) {
        --it;
        dif = min(dif, abs(*it - cur));
      }
      ret += 1LL * dif * dif;
    }
    return ret;
  };

  auto costR = [&](int i) {
    if (sum.count(i)) return -1LL;
    int cur = i;
    for (int j = r; j >= l; --j) {
      cur += a[j];
      if (sum.count(cur)) {
        return -1LL;
      }
    }
    a[r+1] = i;
    cur = 0;
    long long ret = 0;
    for (int j = r+1; j >= l; --j) {
      cur += a[j];
      auto it = sum.lower_bound(cur);
      assert(it == sum.end() || *it != cur);
      int dif = 1e9;
      if (it != sum.end())
        dif = min(dif, abs(*it - cur));
      if (it != sum.begin()) {
        --it;
        dif = min(dif, abs(*it - cur));
      }
      ret += 1LL * dif * dif;
    }
    return ret;
  };
  while (true) {
    int found = -1;
    long long best = -1;
    int cnt = 0, w = 0;;
    for (cnt = 0, id = 0; cnt < (int)p.size(); id = (id+1) % p.size(), ++cnt) {
      long long res = costR(p[id]);
      if (res == -1) continue;
      if (best < res) {
        found = p[id];
        best = res;
      }
      ++w;
      if (w > 10)
        break;
    }
    if (found == -1) break;
    assert(addR(found));
    // cerr << r-l+1 << " wow! " << found << endl;
  }
  vector<int> result(a.begin() + l, a.begin() + r + 1);
  return result;
}

const int mod = 29989;


int main() {
  auto seed = time(0);
  srand(seed);
  cerr << " seed : " << seed << endl;
  vector<int> a;

  auto update = [&](vector<int> v) {
    cerr << " attempt " << v.size() << " " << a.size() << endl;
    if (v.size() <= a.size())
      return;
    a.swap(v);
    for (int x : a)
      cerr << x << " ";
    cerr << endl;
    cerr << " found " << a.size() << endl;

  };

  vector<int> p;
  p.resize(A);
  iota(p.begin(), p.end(), 1);
  update(calc(p));

  reverse(p.begin(), p.end());
  update(calc(p));

  random_shuffle(p.begin(), p.end());
  update(calc(p));

  // for (int k = 2; k < 100; ++k) {
  //   iota(p.begin(), p.end(), 1);
  //   reverse(p.begin(), p.end());
  //   for (int i = 0; i + k < (int)p.size(); ++i) {
  //     random_shuffle(p.begin()+i, p.begin()+i+k);
  //   }
  //   vector<int> res = calc(p);
  //   update(res);
  //   cerr << k << " " << res.size() << endl;
  // }

  int n = a.size();
  // scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    printf("%d%c", a[i], i+1 == n ? '\n' : ' ');
  }
  cerr << n << endl;
  return 0;
}
