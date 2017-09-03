#include <bits/stdc++.h>

using namespace std;

const int H = 2, N = 2e6 + 5;

int mod[] = {int(1e9 + 7), int(1e9 + 9)};
int p[] = {37, 39};
int pp[H][N];

struct hashh {
  int n;
  long long h[H];
  hashh(){}
  hashh(int k, long long a, long long b) : n(k) {
    h[0] = a % mod[0];
    h[1] = b % mod[1];
  }
  hashh operator+(hashh other) {
    hashh res;
    res.n = n + other.n;
    for (int i = 0; i < H; i++) {
      res.h[i] = (h[i] + other.h[i] * pp[i][n]) % mod[i]; 
    }
    return res;
  }
  bool operator<(hashh b) const {
    if (n != b.n)
      return n < b.n;
    if (h[0] != b.h[0])
      return h[0] < b.h[0];
    return h[1] < b.h[1];
  }
};

map<hashh, int > mp;
vector< int > g[N];
hashh res[N];

vector< hashh > ch;
void dfs(int v) {
  for (int u : g[v]) {
    dfs(u);
  }
  ch.clear();
  for (int u : g[v]) {
    ch.push_back(res[u]);
  }
  res[v] = hashh(1, 2, 3);
  sort(ch.begin(), ch.end());
  for (hashh h : ch)
    res[v] = res[v] + h;
  res[v] = res[v] + hashh(1, 5, 7);
}

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < H; i++) {
    long long cur = 1;
    for (int j = 0; j < N; j++) {
      pp[i][j] = cur;
      cur = (cur * p[i]) % mod[i];
    }
  }
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
      g[i].clear();
    for (int i = 1; i < n; i++) {
      int a, b;
      scanf("%d %d", &a, &b);
      a--; b--;
      g[a].push_back(b); 
    }
    dfs(0);
    mp.clear();
    for (int i = 0; i < n; i++)
      mp[res[i]]++;
    pair<int, int> ans(0, 0);
    for (auto it = mp.begin(); it != mp.end(); it++) {
      if (it->second < 2) continue;
      ans = max(ans, make_pair(it->first.n, it->second));
    }
    printf("%d %d\n", ans.first/2, ans.second);
  }
  return 0;
}