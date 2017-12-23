#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

char s[N];
int bit[N];
int get(int x) {
  int ret = 0;
  for (; x; x -= x&-x)
    ret += bit[x];
  return ret;
}

void upd(int x, int v) {
  for (; x < N; x += x&-x)
    bit[x] += v;
}

int get(int l, int r) {
  return get(r) - (l > 0 ? get(l-1) : 0);
}
set<int> st[26];
bool used[N];

int main() {
  scanf("%s", s+1);
  int n = strlen(s+1);
  for (int i = 1; i <= n; ++i) {
    s[i] -= 'a';
    st[s[i]].insert(i);
  }
  int cnt = 0;
  for (int i = 0; i < 26; ++i)
    cnt += st[i].size() & 1;
  if (cnt > 1) {
    puts("-1");
    return 0;
  }
  for (int i = 1; i <= n; ++i)
    upd(i, +1);
  long long ans = 0;
  for (int l = 1, r = n; l < r; ) {
    while (l < r && used[l]) ++l;
    while (l < r && used[r]) -- r;
    if (l >= r) break;
    if (st[s[l]].size() == 1) {
      int b = *st[s[r]].begin();
      ans += get(b-1);
      used[b] = 1;
      used[r] = 1;
      upd(b, -1);
      upd(r, -1);
      st[s[r]].erase(b);
      st[s[r]].erase(r);
    }
    else {
      int b = *st[s[l]].rbegin();
      ans += get(b+1, n);
      upd(b, -1);
      upd(l, -1); 
      used[l] = 1;
      used[b] = 1;
      st[s[l]].erase(b);
      st[s[l]].erase(l);
    }
  }
  cout << ans << endl;
  return 0;
}