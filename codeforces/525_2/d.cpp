#include <bits/stdc++.h>

using namespace std;

map<pair<int, int>, int> mp;
int ask(int c, int d) {
  pair<int, int> cur = make_pair(c, d);
  if (mp.count(cur))
    return mp[cur];
  printf("? %d %d\n", c, d);
  fflush(stdout);
  int ans;
  scanf("%d", &ans);
  // assert(-1 <= ans && ans <= 1);
  return mp[cur] = ans;
}

void answer(int a, int b) {
  printf("! %d %d\n", a, b);
  fflush(stdout);
  exit(0);
}

int main() {
  int a, b;
  a = b = 0;
  int mask = 0;
  for (int i = 29; i >= 0; --i) {
    int o = ask(a | (1 << i), b | (1 << i)), z = ask(a, b);
    if (o == z) {
      mask |= 1 << i;
      continue;
    }
    if (z < 0)
      b |= 1 << i;
    else
      a |= 1 << i;
  }
  for (int i = 0; i < 30; ++i) {
    if (!(mask & (1 << i))) continue;
    int res = ask(a | (1 << i), b);
    if (res < 0) {
      a |= 1 << i;
      b |= 1 << i;
    }
  }
  answer(a, b);
  return 0;
}