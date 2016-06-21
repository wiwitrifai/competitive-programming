#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 6;
vector< pair<int, int> > ch[N];
int n, a[N];
int dfs(int v, long long res = 0) {
  if(res > a[v])
    return 0;
  if(res < 0)
    res = 0;
  int ret = 1;
  for(auto it : ch[v]) {
    ret += dfs(it.first, res+it.second);
  }
  return ret;
}
int main() {
  scanf("%d", &n);
  for(int i = 0; i<n; i++)
    scanf("%d", a+i);
  for(int i = 1; i<n; i++) {
    int p, c;
    scanf("%d%d", &p, &c);
    p--;
    ch[p].emplace_back(i, c);
  }
  cout << n - dfs(0, 0LL) << endl;
  return 0;
}