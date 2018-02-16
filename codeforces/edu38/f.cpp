#include <bits/stdc++.h>

using namespace std;

const int N = 5050;

bitset<N> vis;
char s[N];
vector<int> st;
void dfs(int v, int s) {
  if (vis[v]) return;
  vis[v] = 1;
  st.push_back(v);
  for (int i = 1; i <= s; i <<= 1) if (s & i)
    dfs(v+i, s^i);
}

int main() {
  scanf("%s", s);
  int n = strlen(s);
  int lg = 31 - __builtin_clz(n);
  int hapus = (1 << lg) - 1;
  for (int i = 0; i <= hapus; ++i)
    st.push_back(i);
  int sisa = n - hapus;
  for (int i = 0; i < sisa; ++i) {
    char ans = 'z';
    for (int x : st)
      ans = min(ans, s[x]);
    vector<int> siki;
    siki.swap(st);
    vis.reset();
    for (int x : siki) if (s[x] == ans) {
      int s = x - i;
      dfs(x+1, s^hapus);
    }
    printf("%c", ans);
  }
  printf("\n");
  return 0;
}