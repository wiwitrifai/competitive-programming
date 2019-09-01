#include <bits/stdc++.h>

using namespace std;

const char DELIM = '#';

struct SuffixArray {
  string s;
  int n;
  vector<int> sa, pos, lcp, tmp, cnt, len;
  vector<vector<int>> sparse;

  SuffixArray(string t) : s(t) {
    n = s.size();
    sa.assign(n, 0);
    pos.assign(n, 0);
    tmp.assign(n, 0);
    cnt.assign(max(n, 256), 0);
    lcp.assign(n-1, 0);
    sparse.clear();
    len.assign(n, 0);
    for (int i = n-1, cur = 0; i >= 0; --i) {
      ++cur;
      if (s[i] == DELIM)
        cur = 0;
      len[i] = cur;
    }
    BuildSA();
    BuildLCP();
  }

  void CountingSort(int gap) {
    fill(cnt.begin(), cnt.end(), 0);
    for (int i = 0; i < n; ++i) {
      if (i + gap >= n) {
        ++cnt[0];
        continue;
      }
      ++cnt[pos[i+gap] + 1];
    }
    int sum = 0;
    for (int i = 0; i < (int)cnt.size(); ++i) {
      int cur = cnt[i];
      cnt[i] = sum;
      sum += cur;
    }
    for (int i = 0; i < n; ++i) {
      int cur = sa[i];
      if (cur + gap >= n)
        tmp[cnt[0]++] = cur;
      else
        tmp[cnt[pos[cur + gap] + 1]++] = cur;
    }
    for (int i = 0; i < n; ++i)
      sa[i] = tmp[i];
  }

  void BuildSA() {
    for(int i = 0; i < n; ++i)
      sa[i] = i, pos[i] = s[i];
    for(int gap = 1;; gap <<= 1) {
      auto cmp = [&](int a, int b) {
        if(pos[a] - pos[b])
          return pos[a] < pos[b];
        a += gap; b += gap;
        return (a < n && b < n) ? pos[a] < pos[b] : a > b;
      };
      // sort(sa.begin(), sa.end(), cmp);
      CountingSort(gap);
      CountingSort(0);
      tmp[0] = 0;
      for(int i = 1; i < n; ++i) tmp[i] = tmp[i-1] + cmp(sa[i-1], sa[i]);
      for(int i = 0; i < n; ++i) pos[sa[i]] = tmp[i];
      if(tmp[n-1] == n-1) break;
    }
  }

  void BuildLCP() {
    for(int i = 0, k = 0; i < n; ++i) if(pos[i] - n + 1) {
      for(int j = sa[pos[i] + 1]; s[j + k] == s[i + k] && s[j + k] != DELIM; ++k);
      lcp[pos[i]] = k;
      if(k) k--;
    }
    sparse.push_back(lcp);
    for (int i = 0; ; ++i) {
      int len = n - (1 << (i+1));
      if (len <= 0) break;
      sparse.push_back(vector<int>(len));
      for (int j = 0; j < len; ++j) {
        int left = sparse[i][j], right = sparse[i][j+(1 << i)];
        sparse[i+1][j] = min(left, right);
      }
    }
  }

  int GetLCP(int l, int r) {
    assert(l <= r);
    if (l == r) {
      return len[sa[l]];
    }
    int len = r-l;
    int lg = 31 - __builtin_clz(len);
    return min(sparse[lg][l], sparse[lg][r-(1<<lg)]);
  }

  pair<int, int> FindOccurs(int p, int len) {
    pair<int, int> ret = {p, p};
    int lo = 0, hi = p;
    while (lo < hi) {
      int mid = (lo + hi) >> 1;
      if (GetLCP(mid, p) < len)
        lo = mid + 1;
      else
        hi = mid;
    }
    ret.first = lo;

    lo = p, hi = n-1;
    while (lo < hi) {
      int mid = (lo + hi + 1) >> 1;
      if (GetLCP(p, mid) < len)
        hi = mid - 1;
      else
        lo = mid;
    }
    ret.second = hi;

    return ret;
  }
};

const int N = 2e6 + 6, mod = 1e9 + 7;

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}

struct SegTree {
  int n;
  vector<int> mul;
  SegTree(int n) : n(n), mul(n << 2, 0) {};
  void Update(int x, int v) {
    Update_(x, v, 1, 0, n);
  }
  void Update_(int x, int v, int id, int l, int r) {
    if (r-l < 2) {
      mul[id] = v % mod;
      return;
    }
    int mid = (l + r) >> 1, il = id << 1, ir = il | 1;
    if (x < mid)
      Update_(x, v, il, l, mid);
    else
      Update_(x, v, ir, mid, r);
    mul[id] = 1LL * mul[il] * mul[ir] % mod;
  }
};

char buffer[N];

int main() {
  int n;
  scanf("%d", &n);
  vector<int> len(n), offs(n);
  int m = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%s", buffer+m);
    offs[i] = m;
    len[i] = strlen(buffer+m);
    m += len[i];
    buffer[m++] = DELIM;
  }
  buffer[m] = 0;
  SuffixArray sa(buffer);
  vector<pair<int, int>> ranges;
  int now = 0;
  long long q = 1;
  ranges.emplace_back(0, m-1);
  vector<int> from(m, -1);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < len[i]; ++j) {
      from[now] = i;
      ranges.push_back(sa.FindOccurs(sa.pos[now++], len[i] - j));
    }
    long long cur = 1LL * len[i] * (len[i] + 1) / 2;
    cur %= mod;
    q = q * cur % mod;
    ++now;
  }
  assert(now == m);
  sort(ranges.begin(), ranges.end(), [](auto le, auto ri) {
    if (le.first == ri.first)
      return le.second > ri.second;
    return le.first < ri.first;
  });
  ranges.erase(unique(ranges.begin(), ranges.end()), ranges.end());
  vector<vector<int>> child(ranges.size());
  vector<int> ancestor;
  for (int i = 0; i < (int)ranges.size(); ++i) {
    while (!ancestor.empty() && ranges[ancestor.back()].second < ranges[i].first)
      ancestor.pop_back();
    if (!ancestor.empty()) {
      assert(ranges[ancestor.back()].first <= ranges[i].first && ranges[i].second <= ranges[ancestor.back()].second);
      child[ancestor.back()].push_back(i);
    }
    else
      assert(i == 0);
    ancestor.push_back(i);
  }
  SegTree segtree(n);
  vector<int> cnt(n, 0);
  auto add = [&](int id, int v) {
    if (from[sa.sa[id]] == -1) return;
    id = from[sa.sa[id]];
    cnt[id] += v;
    segtree.Update(id, cnt[id]);
  };
  function<int(int, int)> solve;
  solve = [&](int v, int last)->int {
    int cur = sa.GetLCP(ranges[v].first, ranges[v].second);
    int big = -1;
    for (int u : child[v]) {
      if (big == -1 || ranges[u].second - ranges[u].first > ranges[big].second - ranges[big].first)
        big = u;
    }
    int ret = 0;
    for (int u : child[v]) {
      if (u == big) continue;
      ret += solve(u, cur);
      if (ret >= mod)
        ret -= mod;
      for (int i = ranges[u].first; i <= ranges[u].second; ++i)
        add(i, -1);
    }
    if (big != -1) {
      ret += solve(big, cur);
      if (ret >= mod)
        ret -= mod;
      for (int i = ranges[v].first; i < ranges[big].first; ++i)
        add(i, +1);
      for (int i = ranges[big].second + 1; i <= ranges[v].second; ++i)
        add(i, +1);
    }
    else {
      for (int i = ranges[v].first; i <= ranges[v].second; ++i)
        add(i, +1);
    }
    ret = (ret + 1LL * (cur - last) * segtree.mul[1]) % mod;
    if (ret < 0)
      ret += mod;
    return ret;
  };
  long long p = solve(0, 0);
  long long ans = p * powmod(q, mod-2) % mod;
  if (ans < 0)
    ans += mod;
  cerr << p << " " << q << endl;
  printf("%lld\n", ans);
  return 0;
}
