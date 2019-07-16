#include <bits/stdc++.h>

using namespace std;

int p[] = {11, 13}, pp[2];
int mod[] = {int(1e9+7), int(1e9+9)};

int a[11];

set<pair<int, int> > st;

vector<char> ans;
int n, m, k;
deque<char> dq;
bool dfs(int h0 = 0, int h1 = 0, int depth = 0) {
  if (depth >= k) {
    ans.clear();
    return true;
  }
  char now = dq.front();
  dq.pop_front();
  h0 = (1LL * h0 * p[0]) % mod[0];
  h1 = (1LL * h1 * p[1]) % mod[1];
  if (h0 < 0) h0 += mod[0];
  if (h1 < 0) h1 += mod[1];
  for (int i = 0; i < m; ++i) {
    h0 += i;
    h1 += i;
    if (h0 >= mod[0]) h0 -= mod[0];
    if (h1 >= mod[1]) h1 -= mod[1];
    if (!st.count(make_pair(h0, h1))) {
      st.insert(make_pair(h0, h1));
      dq.push_back(i);
      int f0 = (h0 - 1LL * now * pp[0]) % mod[0];
      int f1 = (h1 - 1LL * now * pp[1]) % mod[1];
      if (f0 < 0) f0 += mod[0]; 
      if (f1 < 0) f1 += mod[1]; 
      bool res = dfs(f0, f1, depth+1);
      ans.push_back(i);
      dq.pop_back();
      if (ans.size() > k || res) {
        dq.push_front(now);
        return true;
      }
    }
    h0 -= i;
    h1 -= i;
    if (h0 < 0) h0 += mod[0];
    if (h1 < 0) h1 += mod[1];
  }
  dq.push_front(now);
  return false;
}

int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < 2; ++i) {
    pp[i] = 1;
    for (int j = 0; j < n-1; ++j)
      pp[i] = 1LL * pp[i] * p[i] % mod[i];
  }
  for (int i = 0; i < m; ++i)
    scanf("%d", a+i);
  if (n == 1) {
    assert(k <= m);
    for (int i = 0; i < k; ++i)
      printf("%d", a[i]);
    printf("\n");
  }
  else {
    for (int i = 0; i < n-1; ++i) {
      dq.push_back(0);
    }
    dfs(0, 0);
    for (int i = 0; i < n-1; ++i)
      ans.push_back(0);
    reverse(ans.begin(), ans.end());
    if (ans.size() > n+k-1)
      ans.resize(n+k-1);
    assert(ans.size() == n+k-1);
    for (int x : ans)
      printf("%d", a[x]);
    printf("\n");
  }
  return 0;
}