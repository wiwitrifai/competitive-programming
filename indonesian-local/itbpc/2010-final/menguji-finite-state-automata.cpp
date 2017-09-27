#include <bits/stdc++.h>

using namespace std;

const int N = 5050;

int n;
struct state {
  int to[N];
  state() {
    for (int i = 0; i < n; i++)
      to[i] = i;
  }
  state operator+(const state& s) {
    state ret;
    for (int i = 0; i < n; i++)
      ret.to[i] = s.to[to[i]];
    return ret;
  }
  state operator*(long long x) const {
    state ret;
    for (state b = *this; x; x >>= 1, b = b + b)
      if (x & 1)
        ret = ret + b;
    return ret;
  }
};

state op[27];

char s[N];
int id, len;

state go() {
  id++;
  if (id >= len || s[id] == ')')
    return state();
  if (s[id] >= 'a' && s[id] <= 'z') {
    int x = s[id] - 'a';
    return op[x] + go();
  }
  long long mul = 0;
  while (s[id] >= '0' && s[id] <= '9') {
    mul *= 10;
    mul += s[id++] - '0';
  }
  assert(s[id] == '(');
  state res = go() * mul;
  return res + go();
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < 27; i++)
      op[i] = state();
    for (int i = 0; i < m; i++) {
      int u, v;
      char c;
      scanf("%d %d %c", &u, &v, &c);
      u--; v--;
      c -= 'a';
      op[c].to[u] = v;
    }
    scanf("%s", s);
    len = strlen(s);
    id = -1;
    state ans = go();
    printf("%d\n", ans.to[0]+1);
  }
  return 0;
}