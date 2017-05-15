#include <bits/stdc++.h>

using namespace std;

const int N = 10050;

string name[N];
char buf1[N], buf2[N];
vector < int > g[N];
int in[N];
map< string, int > mp;

int main() {
  int m, n;
  scanf("%d", &m);
  assert(1 <= m && m <= 10000);
  n = 0;
  for (int i = 0; i < m; i++) {
    scanf("%s lebih baik dari %s", buf1, buf2);
    int u, v;
    if (!mp.count(string(buf1)))
      u = n, name[n] = string(buf1), mp[name[n]] = n, n++;
    else
      u = mp[string(buf1)];
    if (!mp.count(string(buf2)))
      v = n, name[n] = string(buf2), mp[name[n]] = n, n++;
    else
      v = mp[string(buf2)];
    in[v]++;
    g[u].push_back(v);
  }
  stack< int > st;
  for (int i = 0; i < n; i++) {
    if (in[i] == 0)
      st.push(i);
    assert(1 <= name[i].size() && name[i].size() <= 10);
  }
  vector< int > ans;
  while (!st.empty()) {
    int v = st.top(); st.pop();
    ans.push_back(v);
    for (int u : g[v]) {
      in[u]--;
      if (in[u] == 0)
        st.push(u);
    }
  }
  if (ans.size() != n)
    puts("Tidak Mungkin");
  else
    for (int v : ans)
      cout << name[v] << '\n';
  return 0;
}