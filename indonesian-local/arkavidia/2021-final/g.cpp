#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char s[N];

const int K = 2;
vector<int> base = {13, 19, 23, 29};
vector<int> mod = {int(1e9 + 7), int(1e9 + 9), 998244353, int(1e9 + 7)};
vector<vector<int>> powbases = {{1}, {1}, {1}, {1}};

int powbase(int k, int e) {
  int sz = powbases[k].size();
  if (e < sz)
    return powbases[k][e];
  powbases[k].resize(e+1);
  for (int i = sz; i <= e; ++i) {
    powbases[k][i] = powbases[k][i-1] * (long long)base[k] % mod[k];
  }
  return powbases[k][e];
}

struct Hashv {
  int v[K];
  Hashv(int x = 0) {
    for (int i = 0; i < K; ++i)
      v[i] = x;
  }

  Hashv operator+(Hashv h) {
    Hashv r;
    for (int i = 0; i < K; ++i) {
      r.v[i] = v[i] + h.v[i];
      if (r.v[i] <= mod[i])
        r.v[i] -= mod[i];
    }
    return r;
  }

  Hashv operator-(Hashv h) {
    Hashv r;
    for (int i = 0; i < K; ++i) {
      r.v[i] = v[i] - h.v[i];
      if (r.v[i] < 0)
        r.v[i] += mod[i];
    }
    return r;
  }

  Hashv operator<<(int e) {
    Hashv r;
    for (int i = 0; i < K; ++i) {
      r.v[i] = ((long long)v[i] * powbase(i, e)) % mod[i];
    }
    return r;
  }

  bool operator==(Hashv h) {
    for (int i = 0; i < K; ++i) {
      if (v[i] != h.v[i])
        return false;
    }
    return true;
  }
};

ostream& operator<<(ostream& os, Hashv h) {
  os << "(";
  for (int i = 0; i < K; ++i)
    os << h.v[i] << ",";
  return os << ")";
}

void solve() {
  int n;
  scanf("%d", &n);
  scanf("%s", s);
  int cycle = n * 2;
  for (int i = n; i < cycle; ++i) {
    s[i] = s[i-n];
  }
  vector<vector<Hashv>> sumhash(cycle+1, vector<Hashv>(10, 0));
  for (int i = 0; i < cycle; ++i) {
    int now = s[i] - '0';
    for (int j = 0; j < 10; ++j) {
      sumhash[i+1][j] = (sumhash[i][j] << 1) + Hashv(now);
      ++now;
      if (now >= 10)
        now -= 10;
    }
  }
  auto get = [&](int pos, int len) {
    int add = ('0' + 10 - s[pos]) % 10;
    return sumhash[pos+len][add] - (sumhash[pos][add] << len);
  };
  auto cmp = [&](int l, int r) {
    int low = 0, hig = n;
    while (low < hig) {
      int mid = (low + hig + 1) >> 1;
      auto resl = get(l, mid);
      auto resr = get(r, mid);
      if (resl == resr) {
        low = mid;
      } else {
        hig = mid - 1;
      }
    }
    if (low == n)
      return false;
    int lef = s[l+low] - s[l], rig = s[r+low] - s[r];
    if (lef < 0) lef += 10;
    if (rig < 0) rig += 10;
    return lef < rig;
  };
  vector<int> id(n);
  int pos = 0;
  for (int i = 1; i < n; ++i) {
    if (cmp(i, pos)) {
      pos = i;
    }
  }
  int shift = ('0' + 10 - s[pos]) % 10;
  for (int i = 0; i < n; ++i) {
    int cur = i + pos;
    int now = s[cur] - '0';
    int ans = now + shift;
    if (ans >= 10)
      ans -= 10;
    printf("%d", ans);
  }
  printf("\n");
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
