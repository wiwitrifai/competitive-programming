#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5, inf = 1e9 + 7;
vector< int > adj[N];
int to[N][4];
int x[N][2], y[N][2], cnt[N];
int ans[N];
bool cek[N][4];

vector< pair<pair<int, int>, pair<int, int> > > evy[N * 2], evx[N * 2]; 
vector< int > ve;
time_t start_t;

const int boom = 1950;
bool solve(int id) {
  if (id < 0)
    return 1;
  int v = ve[id];
  memset(cek[id], 0, sizeof cek[id]);
  for (int i = 0; i < 4; i++) {
    for (int u : adj[v])
      cek[id][ans[u]] = 1;
  }
  ans[v] = 0;
  while (ans[v] < 4) {
    while (ans[v] < 4 && cek[id][ans[v]]) ans[v]++;
    if (ans[v] < 4 && solve(id-1))
      return true;
    int now = (clock()-start_t) * 1000LL/CLOCKS_PER_SEC;
    if (now > start_t)
      return false;
    ans[v]++;
  }
  return false;
}

int main() {
  start_t = clock();
  int n;
  scanf("%d", &n);
  vector< int > vx, vy;
  for (int i = 0; i < n; i++) {
    scanf("%d %d %d %d", x[i], y[i], x[i]+1, y[i]+1);
    // cerr << x[i][0] << " " << x[i][1] << endl;
    vx.push_back(x[i][0]);
    vx.push_back(x[i][1]);
    vy.push_back(y[i][0]);
    vy.push_back(y[i][1]);
  }
  sort(vx.begin(), vx.end());
  vx.erase(unique(vx.begin(), vx.end()), vx.end());
  sort(vy.begin(), vy.end());
  vy.erase(unique(vy.begin(), vy.end()), vy.end());
  for (int i = 0; i < n; i++) {
    int id = lower_bound(vx.begin(), vx.end(), x[i][0]) - vx.begin();
    evx[id].push_back({{y[i][0], y[i][1]}, {i, 0}});
    id = lower_bound(vx.begin(), vx.end(), x[i][1]) - vx.begin();
    evx[id].push_back({{y[i][0], y[i][1]}, {i, 1}});

    id = lower_bound(vy.begin(), vy.end(), y[i][0]) - vy.begin();
    evy[id].push_back({{x[i][0], x[i][1]}, {i, 0}});
    id = lower_bound(vy.begin(), vy.end(), y[i][1]) - vy.begin();
    evy[id].push_back({{x[i][0], x[i][1]}, {i, 1}});
  }
  for (int i = 0; i < vx.size(); i++) {
    // cerr << vx[i] << " " << evx[i].size() << endl;
    sort(evx[i].begin(), evx[i].end());
    pair< int, int > up = {-inf, -inf-1}, down = {-inf, -inf-1};
    int iup = -1, idown = -1;
    for (auto it : evx[i]) {
      if (it.second.second)
        up = it.first, iup = it.second.first;
      else
        down = it.first, idown = it.second.first;
      if (iup != -1 && idown != -1) {
        if (up.first < down.second && down.first < up.second)
          adj[iup].push_back(idown);
      }
    }
  }
  for (int i = 0; i < vy.size(); i++) {
    sort(evy[i].begin(), evy[i].end());
    pair< int, int > le = {-inf, -inf-1}, ri = {-inf, -inf-1};
    int ile = -1, iri = -1;
    for (auto it : evy[i]) {
      if (it.second.second)
        le = it.first, ile = it.second.first;
      else
        ri = it.first, iri = it.second.first;
      if (ile != -1 && iri != -1) {
        if (le.first < ri.second && ri.first < le.second)
          adj[ile].push_back(iri);
      }
    }
  }
  memset(cnt, 0, sizeof cnt);
  for (int i = 0; i < n; i++) {
    sort(adj[i].begin(), adj[i].end());
    adj[i].erase(unique(adj[i].begin(), adj[i].end()), adj[i].end());
    for (int u : adj[i]) {
      cnt[u]++;
      // cerr << i << "-" << u << endl;
    }
  }
  stack< int > st;
  for (int i = 0; i < n; i++) if (!cnt[i])
    st.push(i);
  while (!st.empty()) {
    int u = st.top(); st.pop();
    ve.push_back(u);
    for (int v : adj[u]) {
      cnt[v]--;
      if (cnt[v] == 0)
        st.push(v);
    }
  }
  // cerr << ve.size() << endl;
  bool ok = solve((int)ve.size() - 1);
  if (!ok) {
    puts("NO");
    return 0;
  }
  puts("YES");
  for (int i = 0; i < n; i++)
    printf("%d\n", ans[i]+1);
  return 0;
}