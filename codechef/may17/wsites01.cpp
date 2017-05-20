#include <bits/stdc++.h>

using namespace std;

const int N =  3e5 + 5;

char s[N];
int sa[N], pos[N], lcp[N], tmp[N], gap, n, len[N];

bool cmp_sa(int a, int b) {
  if(pos[a] - pos[b])
    return pos[a] < pos[b];
  a += gap; b += gap;
  return (a < n && b < n) ? pos[a] < pos[b] : a > b;
}

void build_sa() {
  for(int i = 0; i<n; i++)
    sa[i] = i, pos[i] = s[i];
  for(gap = 1;; gap <<= 1) {
    sort(sa, sa + n, cmp_sa);
    for(int i = 1; i<n; i++) tmp[i] = tmp[i-1] + cmp_sa(sa[i-1], sa[i]);
    for(int i = 0; i<n; i++) pos[sa[i]] = tmp[i];
    if(tmp[n-1] == n-1) break;
  }
}

void build_lcp() {
  for(int i = 0, k = 0; i<n; i++) if(pos[i] - n + 1) {
    for(int j = sa[pos[i] + 1]; s[j + k] == s[i + k] && s[j + k] != '#'; k++);
    lcp[pos[i]] = k;
    if(k) k--;
  }
}

int off[N];
bool add[N];
int id[N], ans[N];
char sad[10];

int main() {
  int m;
  scanf("%d", &m);
  n = 0;
  memset(id, -1, sizeof id);
  for (int i = 0; i < m; i++) {
    scanf("%s %s", sad, s+n);
    len[i] = strlen(s+n);
    off[i] = n;
    id[n] = i;
    s[n+len[i]] = '#';
    n += len[i]+1;
    add[i] = (sad[0] == '+');
  }
  build_sa();
  build_lcp();
  int now = n;
  bool ada = 0;
  for (int i = 0; i < n; i++) {
    int c = sa[i];
    if (id[c] != -1) {
      int x = id[c];
      if (add[x])
        now = n, ada = 1;
      else
        ans[x] = ada ? now : 0;
    }
    now = min(lcp[i], now);
  }
  now = -1;
  ada = 0;
  for (int i = n-1; i >= 0; i--) {
    int c = sa[i];
    if (id[c] != -1) {
      int x = id[c];
      if (add[x])
        now = n, ada = 1;
      else
        ans[x] = max(ans[x], ada ? now : 0);
    }
    if (i)
      now = min(lcp[i-1], now);
  }
  set< string > st;
  for (int i = 0; i < m; i++) if (!add[i]) {
    if (ans[i] >= len[i]) {
      puts("-1");
      return 0;
    }
    st.insert(string(s+off[i], s+off[i]+ans[i]+1));
  }
  printf("%d\n", st.size());
  for (string ss : st)
    cout << ss << '\n';
  return 0;
}