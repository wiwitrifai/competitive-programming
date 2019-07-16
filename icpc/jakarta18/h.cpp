#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int p[N];
int a[N], b[N], c[N], d[N];
int sum[N], cnt[N];
vector<int> add[N], rem[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  sum[0] = cnt[0] = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", p+i);
    sum[i+1] = sum[i] + p[i];
    cnt[i+1] = cnt[i] + (p[i] == 0);
  }
  for (int i = 0; i < k; ++i) {
    scanf("%d %d %d", a+i, b+i, c+i);
    --a[i];
    int s = sum[b[i]] - sum[a[i]], zero = cnt[b[i]] - cnt[a[i]];
    int res = s + zero;
    if (res < c[i]) {
      puts("Impossible");
      return 0;
    }
    d[i] = min((res-c[i]) / 2, zero);
    add[a[i]].push_back(i);
    rem[b[i]].push_back(i);
  }
  int cur = 0;
  set<pair<int, int> > st;
  for (int i = 0; i < n; ++i) {
    for (int id : add[i]) {
      d[id] += cur;
      st.insert(make_pair(d[id], id));
    }
    for (int id : rem[i]) {
      st.erase(make_pair(d[id], id));
    }
    if (p[i] != 0) continue;
    p[i] = 1;
    if (st.empty() || cur+1 <= st.begin()->first) {
      p[i] = -1;
      ++cur;
    }
  }
  for (int i = 0; i < n; ++i)
    printf("%d%c", p[i], i == n-1 ? '\n' : ' ');
  return 0;
}