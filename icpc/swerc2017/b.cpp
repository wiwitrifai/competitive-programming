#include <bits/stdc++.h>

using namespace std;

const int N = 2018;

int a[N][N], w[N], pre[N];
int le[N];
long long cnt[N][N];

int main() {
  int n, m, b, q;
  scanf("%d %d %d %d", &n, &m, &b, &q);
  for (int i = 0; i < b; ++i) {
    int l, r, d, u;
    scanf("%d %d %d %d", &l, &r, &d, & u);
    for (int j = l; j < r; ++j)
      for (int k = d; k < u; ++k)
        a[j][k] = 1;
  }
  memset(le, -1, sizeof le);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i][j])
        le[j] = i;
      w[j] = i - le[j];
      pre[j] = -1;
    }
    stack<int> st;
    for (int j = 0; j < m; ++j) {
      while (!st.empty() && w[st.top()] >= w[j]) st.pop();
      if (!st.empty()) pre[j] = st.top();
      else pre[j] = -1;
      st.push(j);
    }
    while (!st.empty()) st.pop();
    for (int j = m-1; j >= 0; --j) {
      while (!st.empty() && w[st.top()] > w[j]) st.pop();
      int rig = (st.empty() ? m : st.top()) -j;
      int lef = j - pre[j]-1;
      cnt[w[j]][rig+lef] += 1;
      cnt[w[j]][lef] -= 1;
      cnt[w[j]][rig-1] -= 1;
      
      st.push(j);
    }
  }
  for (int i = n; i > 0; --i) {
    for (int j = m; j > 0; --j) {
      cnt[i][j-1] += cnt[i][j];
    }
  }
  for (int i = n; i > 0; --i) {
    for (int j = m; j > 0; --j) {
      cnt[i][j-1] += cnt[i][j];
    }
  }
  for (int i = n; i > 0; --i) {
    for (int j = m; j > 0; --j) {
      cnt[i-1][j] += cnt[i][j];
    }
  }
  while (q--) {
    int x, y;
    scanf("%d %d", &x, &y);
    printf("%lld\n", cnt[x][y]);
  }
  return 0;
}
