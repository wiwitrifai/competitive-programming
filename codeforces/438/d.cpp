#include <bits/stdc++.h>

using namespace std;

const int N = 256, M = 5e6 + 4, L = 100;

set< string > st[N];
bitset<M> bs;
string f[N], b[N];
char s[M];
int ans[N];

void process(int id, int mi = 0) {
  while (1) {
    vector<bool> bs(1LL << (mi+1));
    long long all = 1LL << (mi+1);
    all--;
    for (string now : st[id]) {
      long long cur = 0;
      for (int i = 0; i < now.size(); i++) {
        cur <<= 1;
        cur |= now[i]-'0';
        cur &= all;
        if (i >= mi)
          bs[cur] = 1;
      }
    }
    bool ok = 1;
    for (int i = 0; i < bs.size(); i++)
      ok &= bs[i];
    if (!ok) break;
    mi++;
  }
  ans[id] = mi;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", s);
    string cur = string(s);
    f[i] = cur;
    b[i] = cur;
    st[i].insert(cur);
    process(i, 0);
  }
  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    l--; r--;
    f[n+i] = f[l] + f[r];
    b[n+i] = b[l] + b[r];
    if (f[n+i].size() > L)
      f[n+i].resize(L);
    if (b[n+i].size() > L)
      b[n+i].erase(b[n+i].begin(), b[n+i].end() - L);
    st[n+i] = st[l];
    for (string ss : st[r])
      st[n+i].insert(ss);
    string mid = b[l] + f[r];
    st[n+i].insert(mid);
    process(n+i, max(ans[l], ans[r]));
    printf("%d\n", ans[n+i]);
  }

  return 0;
}