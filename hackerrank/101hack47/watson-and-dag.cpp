#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 7;

vector< int > g[N];
int din[N];
int pos[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    g[u].push_back(v); 
    din[v]++;
  }
  set< int > st;
  for (int i = 0; i < n; i++) if (din[i] == 0)
    st.insert(i);
  for (int i = 0; i <= n; i++)
    pos[i] = n;
  int cnt = 0;
  while (!st.empty()) {
    auto it = --st.end();
    int v = *it;
    st.erase(it);
    pos[st.size()] = min(pos[st.size()], cnt++);
    for (int u : g[v]) {
      din[u]--;
      if (din[u] == 0)
        st.insert(u);
    }
  }
  for (int i = n-1; i >=0; i--)
    pos[i] = min(pos[i], pos[i+1]);
  long long ans = 1LL * n * n;
  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    ans += 1LL * (n-i) * pos[i] + sum;
    sum += pos[i];
  }
  cout << ans << endl;
  return 0;
}