#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

pair<int, int> ans[N * 2];

int n;
char resp[N];
map<pair<int, int>, int> mp;

bool ask(int x, int y, int p, int q) {
  ++x, ++y, ++p, ++q;
  int le = x * n + y, ri = p * n + q;
  pair<int, int> state = make_pair(le, ri);
  auto it = mp.find(state);
  if (it != mp.end())
    return it->second;
  int dist = p + q - x - y;
  assert(dist >= n-1);
  printf("? %d %d %d %d\n", x, y, p, q);
  fflush(stdout);
  scanf("%s", resp);
  if (resp[0] == 'Y')
    return mp[state] = 1;
  else if (resp[0] == 'N')
    return mp[state] = 0;
  else {
    assert(false);
    return mp[state] = -1;
  }
}

bool dfs(int x, int y) {
  if (x + y == n-1) {
    assert(make_pair(x, y) == ans[n-1]);
    return true;
  }
  ans[(x+y)] = make_pair(x, y);
  bool bef = true;
  if (y-1 >= ans[n-1].second && (bef = ask(ans[x+y-n].first, ans[x+y-n].second, x, y-1))) {
    bool res = dfs(x, y-1);
    if (res)
      return res;
  }
  if (x-1 >= ans[n-1].first && (!bef || ask(ans[x+y-n].first, ans[x+y-n].second, x-1, y))) {
    bool res = dfs(x-1, y);
    if (res)
      return res;
  }
  return false;
}

int main() {
  scanf("%d", &n);
  ans[0] = make_pair(0, 0);
  for (int i = 1; i <= n-1; ++i) {
    int x = ans[i-1].first, y = ans[i-1].second;
    if (x + 1 < n && ask(x+1, y, n-1, n-1))
      ++x;
    else {
      ++y;
      assert(y < n);
    }
    ans[i] = make_pair(x, y);
  }
  ans[(n-1) * 2] = make_pair(n-1, n-1);
  bool res = dfs(n-1, n-1);
  assert(res);
  printf("! ");
  for (int i = 0; i < n * 2 - 2; ++i) {
    printf("%c", ans[i].first == ans[i+1].first ? 'R' : 'D');
  }
  printf("\n");
  fflush(stdout);
  return 0;
}