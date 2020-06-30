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

const int N = 2e5 + 5, K = 505;

char buffer[N];

const int mod = 998244353;

void add(int & var, int val) {
  var += val;
  if (var >= mod)
    var -= mod;
}

long long powmod(long long b, long long p) {
  long long r = 1;
  for (; p; p >>= 1, b = b * b % mod)
    if (p & 1)
      r = r * b % mod;
  return r;
}

vector<long long> fact(1, 1), inv(1, 1);

long long C(int n, int x) {
  if (n < 0 || n < x || x < 0)
    return 0;
  while ((int)fact.size() <= n) {
    fact.push_back(fact.back() * (long long)fact.size() % mod);
    inv.push_back(powmod(fact.back(), mod-2));
  }
  return (fact[n] * inv[x] % mod) * inv[n-x] % mod;
}

int dp[K];
int k;

void insert_dp(int x) {
  if (x == 0)
    return;
  for (int i = k; i > 0; --i) {
    add(dp[i], 1LL * dp[i-1] * x % mod);
  }
}


void remove_dp(int x) {
  if (x == 0)
    return;
  for (int i = 1; i <= k; ++i) {
    add(dp[i], mod - (1LL * dp[i-1] * x % mod));
  }
}


vector<int> p;

int find(int x) {
  return p[x] < 0 ? x : p[x] = find(p[x]);
}

void merge(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) return;
  remove_dp(-p[y]);
  remove_dp(-p[x]);
  if (-p[y] > -p[x])
    swap(x, y);
  p[x] += p[y];
  p[y] = x;
  insert_dp(-p[x]);
}


void solve() {
  scanf("%s %d", buffer, &k);
  fill(dp+1, dp+k+1, 0);
  dp[0] = 1;
  SuffixArray sa(buffer);
  sa.BuildSA();
  sa.BuildLCP();
  vector<pair<int, int>> separate;
  int n = strlen(buffer);
  for (int i = 0; i < n-1; ++i) {
    separate.emplace_back(sa.lcp[i], i);
  }
  sort(separate.begin(), separate.end());
  reverse(separate.begin(), separate.end());
  vector<int> ans(n);
  p.assign(n, -1);
  long long f = 1;
  for (int i = 1; i <= k; ++i) {
    f = f * i % mod;
  }
  for (int len = n, i = 0; len > 0; --len) {
    insert_dp(1);
    while (i < (int)separate.size() && separate[i].first >= len) {
      int pos = separate[i].second;
      merge(sa.sa[pos], sa.sa[pos+1]);
      ++i;
    }
    ans[len-1] = 1LL * dp[k] * powmod(n-len+1, mod-1-k) % mod;
    ans[len-1] = ans[len-1] * f % mod;
  }
  for (int i = 0; i < n; ++i) {
    if (ans[i] < 0)
      ans[i] += mod;
    printf("%d%c", ans[i], i+1 == n ? '\n' : ' ');
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
