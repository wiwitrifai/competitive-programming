#include <bits/stdc++.h>

using namespace std;

const int N = 105;

vector< int > adj[N];
int a[N], d[N], din[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d %d", a+i, d+i);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j)
        continue;
      if (d[i] < 0) {
        if (make_pair(a[i], -i) > make_pair(a[j], -j) && make_pair(a[j], -j) > make_pair(a[i]+d[i], -i) && 
          make_pair(a[i]+d[i], -i) > make_pair(a[j]+d[j], -j))
          adj[i].push_back(j);
      }
      else {
        if (make_pair(a[i], -i) < make_pair(a[j], -j) && make_pair(a[j], -j) < make_pair(a[i]+d[i], -i) && 
          make_pair(a[i]+d[i], -i) < make_pair(a[j]+d[j], -j))
          adj[i].push_back(j);
      }
    }
  }
  memset(din, 0, sizeof din);
  for (int i = 0; i < n; i++) {
    for (int u : adj[i])
      din[u]++;
  }
  stack < int > st;
  for (int i = 0; i < n; i++) if (din[i] == 0) {
    st.push(i);
  }
  vector< int > order;
  while (!st.empty()) {
    int u = st.top();
    st.pop();
    order.push_back(u);
    for (int v : adj[u]) {
      din[v]--;
      if (din[v] == 0)
        st.push(v);
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int cnt1, cnt2;
    cnt1 = cnt2 = 0;
    for (int j = 0; j < n; j++) {
      if (j == order[i])
        continue;
      cnt1 += (make_pair(a[j], -j) < make_pair(a[order[i]], -order[i]));
      cnt2 += (make_pair(a[j], -j) < make_pair(a[order[i]]+d[order[i]], -order[i]));
    }
    ans += abs(cnt1-cnt2);
    a[order[i]] += d[order[i]];
  }
  printf("%d\n", ans);
  return 0;
}