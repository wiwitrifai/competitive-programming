#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

char s[N];

long long get_ip(char * c, int n) {
  long long ret = 0, cur = 0;
  for (int i = 0; i < n; ++i) {
    if (c[i] == '.') {
      ret += cur;
      ret *= 256;
      cur = 0;
    }
    else {
      cur = cur * 10 + c[i] - '0';
    }
  }
  ret += cur;
  return ret;
}

void print_ip(long long v) {
  vector<int> vp;
  for (int i = 0; i < 4; ++i) {
    vp.push_back(v % 256);
    v /= 256;
  }
  for (int i = 3; i >= 0; --i) {
    if (i < 3)
      printf(".");
    printf("%d", vp[i]);
  }
}

int sum[N];
int trie[N * 32][2];
char mask[N * 32];
int nodes = 0;

vector<pair<long long, int> > ans;

void dfs(int node, long long v, int depth) {
  if (node == 0)
    return;
  if (mask[node] == 1) {
    ans.emplace_back(v, depth);
    return;
  }
  if (mask[node] == 3) {
    dfs(trie[node][0], v, depth+1);
    dfs(trie[node][1], v | (1LL << (31-depth)), depth+1);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  int root = nodes = 1;
  vector<int> all;
  for (int i = 0; i < n; ++i) {
    scanf("%s", s);
    int len = strlen(s);
    int sampe = len;
    for (int j = 0; j < len; ++j) {
      if (s[j] == '/')
        sampe = j;
    }
    long long v = get_ip(s+1, sampe - 1);
    int sign = s[0] == '-' ? 1 : 2;
    int x = 32;
    if (sampe < len) {
      x = 0;
      for (int j = sampe+1; j < len; ++j)
        x = x * 10 + s[j] - '0';
    }
    int cur = root;
    mask[cur] |= sign;
    for (int j = 31; j >= 32-x; --j) {
      int p = (v >> j) & 1;
      if (trie[cur][p] == 0)
        trie[cur][p] = ++nodes;
      cur = trie[cur][p];
      mask[cur] |= sign;
    }
    all.push_back(cur);
  }
  for (int v : all) {
    if (mask[v] == 3) {
      puts("-1");
      return 0;
    }
  }
  dfs(1, 0, 0);
  printf("%d\n", (int)ans.size());
  for (int i = 0; i < ans.size(); ++i) {
    long long v = ans[i].first;
    int k = ans[i].second;
    print_ip(v);
    if (k != 32)
      printf("/%d", k);
    printf("\n");
  }
  return 0;
}