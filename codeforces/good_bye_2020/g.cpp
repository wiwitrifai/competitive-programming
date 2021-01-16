// #pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
// #pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

// #pragma GCC optimze("O3")

#include <bits/stdc++.h>

using namespace std;

struct SuffixArray {
  string s;
  int n;
  vector<int> sa, pos, lcp, tmp, cnt;
  vector<vector<int>> sparse;

  SuffixArray(string t) : s(t) {
    n = s.size();
    sa.assign(n, 0);
    pos.assign(n, 0);
    tmp.assign(n, 0);
    cnt.assign(max(n, 256), 0);
    lcp.assign(n-1, 0);
    sparse.clear();
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
      for(int j = sa[pos[i] + 1]; s[j + k] == s[i + k]; ++k);
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
    if (l >= r)
      return n;
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

const int LEN = 1e6 + 5, N = 2e5 + 5, mod = 1e9 + 7;

char buffer[LEN];

string readstr() {
  scanf("%s", buffer);
  return buffer;
}

vector<tuple<int, int, int>> que[N];

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  string s0 = readstr();
  string t = readstr();
  vector<int> ans(q, -1);
  int starting = 0;
  vector<pair<int, string>> vws;
  int longest = 0;
  for (int i = 0; i < q; ++i) {
    int k;
    scanf("%d", &k);
    string w = readstr();
    vws.emplace_back(k, w);
    longest = max(longest, (int)w.size());
  }
  string cur = s0;
  while (starting < n && (int)cur.size() < longest) {
    cur = cur + t[starting] + cur;
    ++starting;
  }
  int len = cur.size();
  cur.push_back('#');
  for (int i = 0; i < q; ++i) {
    string & w = vws[i].second;
    int k = vws[i].first;
    int from = cur.size();
    for (char c : w)
      cur.push_back(c);
    que[k].emplace_back(i, from, w.size());
  }
  SuffixArray sa(cur);
  vector<int> fen(cur.size()+1, 0);
  int curlen = s0.size();
  for (int i = 0; i <= starting; ++i) {
    if (i) {
      int nextlen = curlen * 2 + 1;
      curlen = nextlen;
    }
    int cursum = 0;
    for (int j = 0; j < (int)cur.size(); ++j) {
      if (len - curlen <= sa.sa[j] && sa.sa[j] < len)
        ++cursum;
      fen[j+1] = cursum;
    }
    for (auto & it : que[i]) {
      int id, from, sz;
      tie(id, from, sz) = it;
      auto res = sa.FindOccurs(sa.pos[from], sz);
      ans[id] = fen[res.second+1] - fen[res.first];
    }
  }
  auto findLCP = [&](int u, int v) {
    u = sa.pos[u];
    v = sa.pos[v];
    if (u > v)
      swap(u, v);
    return sa.GetLCP(u, v);
  };
  // assert(curlen == len);
  vector<int> cost(26, 0);
  int fcost = 1;
  for (int i = starting+1; i <= n; ++i) {
    for (int j = 0; j < 26; ++j) {
      cost[j] = cost[j] * 2;
      if (cost[j] >= mod)
        cost[j] -= mod;
    }
    int cnow = t[i-1]-'a';
    ++cost[cnow];
    if (cost[cnow] >= mod)
      cost[cnow] -= mod;
    fcost *= 2;
    if (fcost >= mod)
      fcost -= mod;
    for (auto & it : que[i]) {
      int id, from, sz;
      tie(id, from, sz) = it;
      auto res = sa.FindOccurs(sa.pos[from], sz);
      int curans = 1LL * fcost * (fen[res.second+1] - fen[res.first]) % mod;
      for (int j = 0; j < sz; ++j) {
        if (j > 0 && findLCP(from, len-j) < j) continue;
        if (j + 1 < sz && findLCP(from + j + 1, 0) < sz-j-1) continue;
        int cmid = cur[from+j] - 'a';
        curans += cost[cmid];
        if (curans >= mod)
          curans -= mod;
      }
      ans[id] = curans;
    }
  }
  for (int i = 0; i < q; ++i)
    printf("%d\n", ans[i]);
  return 0;
}
