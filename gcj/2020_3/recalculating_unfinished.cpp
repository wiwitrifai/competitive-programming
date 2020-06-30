// Status: unfinished and I think the idea is wrong

#include <bits/stdc++.h>

using namespace std;


template<typename A>
ostream& operator<<(ostream& os, vector<A> v) {
  os << "{";
  for (size_t i = 0; i < v.size(); ++i) {
    if (i)
      os << ", ";
    os << v[i];
  }
  return os << "}";
}

template<typename A, typename B>
ostream& operator<<(ostream& os, pair<A, B> p) {
  return os << "(" << p.first << ", " << p.second << ")";
}

template<typename A, typename B, typename C>
ostream& operator<<(ostream& os, tuple<A, B, C> t) {
  return os << "(" << get<0>(t) << ", " << get<1>(t) << ", " << get<2>(t) << ")";
}

template<typename A, typename B, typename C, typename D>
ostream& operator<<(ostream& os, tuple<A, B, C, D> t) {
  return os << "(" << get<0>(t) << ", " << get<1>(t) << ", " << get<2>(t) << ", " << get<3>(t) << ")";
}

template <size_t N>
ostream& operator<<(ostream& os, bitset<N> b) {
  for (size_t i = 0; i < N; ++i) {
    os << static_cast<char>('0' + b[i]);
  }
  return os;
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:" << (__VA_ARGS__) << endl


long long gcd(long long a, long long b) {
  return a ? gcd(b % a, a) : b;
}

void solve() {
  int n, d;
  scanf("%d %d", &n, &d);
  vector<int> x(n), y(n);
  vector<int> p(n), q(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &x[i], &y[i]);
    p[i] = x[i] + y[i];
    q[i] = x[i] - y[i];
  }
  vector<int> add = p, sub = q;
  vector<int> vp, vq;
  for (int i = 0; i < n; ++i) {
    add.emplace_back(p[i] + d);
    add.emplace_back(p[i] - d);
    sub.emplace_back(q[i] + d);
    sub.emplace_back(q[i] - d);
  }
  auto make_distinct = [](vector<int> & v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
  };
  make_distinct(vp);
  make_distinct(vq);
  while (true) {
    bool ok = true;
    for (int i = 0; i < n; ++i) {
      for (int dp : vp) {
        add.emplace_back(p[i] + dp);
      }
      for (int dq : vq) {
        sub.emplace_back(q[i] + dq);
      }
    }
  }
  make_distinct(add);
  make_distinct(sub);
  vector<vector<pair<int, int>>> dir(add.size() * sub.size());
  int tot = (int)add.size() * sub.size();
  vector<pair<int, int>> sz(tot);
  long long up = 0, down = 0;
  for (int i = 0; i + 1 < (int)add.size(); ++i) {
    for (int j = 0; j + 1 < (int)sub.size(); ++j) {
      int id = i * (int)sub.size() + j;
      int pp = add[i] + add[i+1];
      int qq = sub[j] + sub[j+1];
      sz[id] = {add[i+1] - add[i], sub[j+1] - sub[j]};
      for (int k = 0; k < n; ++k) {
        if (max(abs(2 * p[k] - pp), abs(2 * q[k] - qq)) <= 2 * d)
          dir[id].emplace_back(4 * x[k] - (pp + qq), 4 * y[k] - (pp - qq));
      }
      if (dir[id].size() > 0) {
        down += 1LL * (add[i+1] - add[i]) * (sub[j+1] - sub[j]);
        // sort(dir[id].begin(), dir[id].end());
        cerr << id << " " << pp << " " << qq << " " << sz[id] << " " << dir[id] << endl;
      }
    }
  }
  vector<bool> dup(tot, false);
  for (int i = 0; i < tot; ++i) {
    if (dir[i].empty()) continue;
    for (int j = i+1; j < tot; ++j) {
      if (dir[j].empty()) continue;
      if (dir[i] == dir[j]) {
        dup[i] = dup[j] = true;
      }
    }
  }

  for (int i = 0; i + 1 < (int)add.size(); ++i) {
    for (int j = 0; j + 1 < (int)sub.size(); ++j) {
      int id = i * (int)sub.size() + j;
      if (dir[id].empty()) continue;
      if (!dup[id]) continue;
      up += 1LL * (add[i+1] - add[i]) * (sub[j+1] - sub[j]);
    }
  }
  if (down == 0)
    down = 1;
  cerr << up << " " << down << endl;
  long long g = gcd(up, down);
  up /= g;
  down /= g;
  printf("%lld %lld\n", up, down);
}

int main() {
#ifdef LOCAL
  time_t starttime = clock();
#endif
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    printf("Case #%d: ", tc);
    solve();
#ifdef LOCAL
    cerr << "~ TC#" << tc << " done! execution time: " <<
      (double)(clock()-starttime) / CLOCKS_PER_SEC << " s" << endl;
#endif
  }
  return 0;
}
