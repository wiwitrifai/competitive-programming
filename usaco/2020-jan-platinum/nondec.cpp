#include <bits/stdc++.h>

using namespace std;

const int N = 5e4, K = 20, mod = 1e9 + 7, Q = 2e5 + 5;
int k;

inline int add(int x, int y) {
  x += y;
  if (x >= mod)
    x -= mod;
  return x;
}

struct Dp {
  int v[K];
  Dp() {
    memset(v, 0, sizeof v);
  }
  void add_back(int x) {
    int sum = 1;
    for (int i = 0; i <= x; ++i) {
      sum = add(sum, v[i]);
    }
    v[x] = add(sum, v[x]);
  }
  void add_front(int x) {
    int sum = 1;
    for (int i = k-1; i >= x; --i) {
      sum = add(sum, v[i]);
    }
    v[x] = add(sum, v[x]);
  }
  int get() {
    int ret = 1;
    for (int i = 0; i < k; ++i)
      ret = add(ret, v[i]);
    return ret;
  }
};


struct Node {
  int v[K][K];
  Node() {
    memset(v, 0, sizeof v);
  }

  Node operator*(Node o) {
    Node ret;
    for (int i = 0; i < k; ++i)
      for (int j = 0; j < k; ++j)
        ret.v[i][j] = add(v[i][j], o.v[i][j]);
    for (int i = 0; i < k; ++i) {
      int sum = 0;
      for (int j = i; j < k; ++j) {
        sum = add(sum, v[i][j]);
        for (int z = j; z < k; ++z) {
          ret.v[i][z] = (ret.v[i][z] + 1LL * sum * o.v[j][z]) % mod;
        }
      }
    }
    return ret;
  }
  void add_back(int x) {
    for (int i = 0; i <= x; ++i) {
      int sum = 0;
      for (int j = i; j <= x; ++j) {
        sum = add(sum, v[i][j]);
      }
      v[i][x] = sum;
    }
    v[x][x] = add(v[x][x], 1);
  }
  void add_front(int x) {
    for (int i = x; i < k; ++i) {
      for (int j = i; j < k; ++j) {
        v[x][j] = add(v[x][j], v[i][j]);
      }
    }
    v[x][x] = add(v[x][x], 1);
  }

  Dp get_back() {
    Dp ret;
    for (int i = 0; i < k; ++i) {
      for (int j = i; j < k; ++j) {
        ret.v[j] = add(ret.v[j], v[i][j]);
      }
    }
    return ret;
  }

};

Dp operator*(Dp dp, Node o) {
  Dp ret = dp;
  int sum = 1;
  for (int i = 0; i < k; ++i) {
    sum = add(sum, dp.v[i]);
    for (int j = i; j < k; ++j) {
      ret.v[j] = (ret.v[j] + o.v[i][j] * 1LL * sum) % mod;
    }
  }
  return ret;
}

Dp operator*(Node o, Dp dp) {
  Dp ret = dp;
  int sum = 1;
  for (int i = k-1; i >= 0; --i) {
    sum = add(sum, dp.v[i]);
    for (int j = j; j >= 0; --j) {
      ret.v[j] = (ret.v[j] + o.v[i][j] * 1LL * sum) % mod;
    }
  }
  return ret;
}

ostream& operator<<(ostream& os, Node o) {
  os << "{";
  for (int i = 0; i < k; ++i) {
    os <<"[";
    for (int j = 0; j < k; ++j)
      os << o.v[i][j] << ",";
    os <<"]" << endl;
  }
  return os <<"}";
}

ostream& operator<<(ostream& os, Dp o) {
  os <<"[";
  for (int j = 0; j < k; ++j)
    os << o.v[j] << ",";
  os <<"]";
  return os;
}

int n, a[N], l[Q], r[Q], ans[Q];

const int S = 200, G = N / S + 3;

Node seg[G];
vector<int> que[N];

int main() {
  freopen("nondec.in", "r", stdin);
  freopen("nondec.out", "w", stdout);
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    --a[i];
  }
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    scanf("%d %d", l+i, r+i);
    --l[i];
    que[l[i]].push_back(i);
    ans[i] = 0;
  }
  int ng = (n + S - 1) / S;
  for (int i = n-1; i >= 0; --i) {
    int g = i / S;
    seg[g].add_front(a[i]);
    for (int id : que[i]) {
      int rg = r[id]/S-1;
      Dp cur;
      if (rg >= g)
        cur = seg[g].get_back();
      if (rg > g)
        cur = cur * seg[rg];
      for (int j = max((rg + 1) * S, i); j < r[id]; ++j) {
        cur.add_back(a[j]);
      }
      ans[id] = cur.get();
    }
    if ((i % S) == 0) {
      for (int j = g+1; j < ng; ++j)
        seg[j] = seg[g] * seg[j];
    }
  }
  for (int i = 0; i < q; ++i) {
    printf("%d\n", ans[i]);
  }
  return 0;
}
