#include <bits/stdc++.h>

using namespace std;

const int C = 26, N = 3e5 + 6;

int child[N][C], suff[N];
int cnt[N], nodes = 0;

int new_node() {
  memset(child[nodes], 0, sizeof child[nodes]);
  suff[nodes] = 0;
  cnt[nodes] = 0;
  assert(nodes < N);
  return nodes++;
}

int add(const char * s, int root = 0) {
  int len = strlen(s);
  int b = root;
  int now = root;
  for (int i = 0; i < len; ++i) {
    int c = s[i] - 'a';
    if (!child[now][c]) {
      child[now][c] = new_node();
    }
    now = child[now][c];
  }
  ++cnt[now];
  return now;
}

void bfs(int root = 0) {
  queue<pair<int, int>> que;
  que.emplace(root, root);
  while (!que.empty()) {
    int now = que.front().first, b = que.front().second;
    que.pop();
    suff[now] = b;
    assert(now == 0 || now != b);
    cnt[now] += cnt[b];
    for (int i = 0; i < C; ++i) {
      if (!child[now][i]) continue;
      int cur = b;
      while (cur && !child[cur][i]) {
        cur = suff[cur];
      }
      if (child[cur][i] && cur != now)
        cur = child[cur][i];
      que.emplace(child[now][i], cur);
    }
  }
}

char s[N], p[N];
vector<string> str;

int lef[N], rig[N];

int main() {
  nodes = 0;
  int n;
  scanf("%s %d", s, &n);
  int now = new_node();
  for (int i = 0; i < n; ++i) {
    scanf("%s", p);
    str.push_back(p);
    add(p);
  }
  bfs();
  int len = strlen(s);
  for (int i = 0; i < len; ++i) {
    int c = s[i] - 'a';
    while (now && !child[now][c]) {
      now = suff[now];
    }
    if (child[now][c])
      now = child[now][c];
    lef[i] = cnt[now];
  }
  nodes = 0;
  now = new_node();
  for (string & st : str) {
    reverse(st.begin(), st.end());
    add(st.c_str());
  }
  bfs();
  for (int i = len-1; i >= 0; --i) {
    int c = s[i] - 'a';
    while (now && !child[now][c]) {
      now = suff[now];
    }
    if (child[now][c])
      now = child[now][c];
    rig[i] = cnt[now];
  }
  long long ans = 0;
  for (int i = 0; i + 1 < len; ++i) {
    ans += 1LL * lef[i] * rig[i+1];
  }
  printf("%lld\n", ans);

  return 0;
}
