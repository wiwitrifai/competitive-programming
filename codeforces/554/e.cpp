#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

vector<int> g[N];

int b[N], c[N], pt[N];
bool used[N];
vector<int> ans;

void dfs(int s) {
  while (pt[s] < g[s].size()) {
    int e = g[s][pt[s]++];
    if (used[e]) continue;
    used[e] = 1;
    int u = b[e] ^ c[e] ^ s;
    dfs(u);
  }
  ans.push_back(s);
}

int main() {
  int n;
  scanf("%d", &n);
  vector<int> num;
  for (int i = 0; i < n-1; ++i) {
    scanf("%d", b+i);
    num.push_back(b[i]);
  }
  for (int i = 0; i < n-1; ++i) {
    scanf("%d", c+i);
    num.push_back(c[i]);
  }
  sort(num.begin(), num.end());
  num.erase(unique(num.begin(), num.end()), num.end());
  for (int i = 0; i < n-1; ++i) {
    if (b[i] > c[i]) {
      puts("-1");
      return 0;
    }
    b[i] = lower_bound(num.begin(), num.end(), b[i]) - num.begin();
    c[i] = lower_bound(num.begin(), num.end(), c[i]) - num.begin();
    g[b[i]].push_back(i);
    g[c[i]].push_back(i);
  }
  int cnt = 0;
  for (int i = 0; i < num.size(); ++i) {
    cnt += (int)g[i].size() & 1;
  }
  if (cnt > 2) {
    puts("-1");
    return 0;
  }
  int s = 0;
  for (int i = 0; i < num.size(); ++i)
    if ((int)g[i].size() & 1)
      s = i;
  dfs(s);
  if (ans.size() < n) {
    puts("-1");
    return 0;
  }
  for (int i = 0; i < n; ++i)
    printf("%d%c", num[ans[i]], i == n-1 ? '\n' : ' ');
  return 0;
}
