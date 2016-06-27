#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
vector< int > adj[N];
int n, ans[N], r[N], d[N], c[N], to[N];

int main() {
  scanf("%d", &n);
  set< pair<int, int> > st;
  for(int i = 0; i<n; i++) {
    scanf("%d%d%d", d+i, c+i, r+i);
    for(int j = 0; j<r[i]; j++) {
      int v;
      scanf("%d", &v);
      adj[i].push_back(--v);
      to[v]++;
    }
  }
  for(int i = 0; i<n; i++) if(to[i] == 0)
    st.insert({-d[i], i});
  int no = 0;
  while(!st.empty()) {
    auto it = st.begin();
    int cur = it->second;
    ans[no++] = cur;
    st.erase(it);
    for(auto u : adj[cur]) {
      to[u]--;
      if(to[u] == 0)
        st.insert({-d[u], u});
    }
  }
  if(no < n) {
    puts("NO");
  }
  else {
    long long now = 0;
    bool ok = true;
    for(int i = n-1; i>=0; i--) {
      now += c[ans[i]];
      if(d[ans[i]] < now) {
        ok = false;
        break;
      }
    }
    if(ok) {
      puts("YES");
      for(int i = n-1; i>=0; i--)
        printf("%d ", ans[i]+1);
      printf("\n");
    }
    else
      puts("NO");
  }
  return 0;
}