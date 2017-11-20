#include <bits/stdc++.h>

using namespace std;

const int N = 100000, inf = 1e9 + 7;

int n, s, x;

int val[N], nxt[N];
int cnt = 1999;

void ask(int i) {
  if (val[i] >= 0)
    return;
  if (cnt <= 0) return;
  cnt--;
  assert(i >= 1 && i <= n);
  printf("? %d\n", i);
  fflush(stdout);
  scanf("%d %d", val+i, nxt+i);
}

void ans(int a) {
  assert(cnt >= 0);
  printf("! %d\n", a);
  fflush(stdout); 
}

int bit[N];
void upd(int x, int v) {
  for (; x < N; x += x&-x)
    bit[x] += v;
}
int get(int x) {
  int ret = 0;
  for (int i = 1 << 18; i; i >>= 1) {
    if (ret + i >= N) continue;
    if (bit[ret+i] < x) {
      ret += i;
      x -= bit[ret];
    }
  }
  return ret + 1;
}

int main() {
  cnt = 1998;
  scanf("%d %d %d", &n, &s, &x);
  for (int i = 0; i <= n + 1; i++)
    val[i] = nxt[i] = -2;
  int run = 999;
  double p = 0;
  for (int i = 1; i <= 1998; i++) {
    double pp = 0;
    for (int j = max(i, n+i-1998); j <= n; j++) {
      pp *= (double)(j-i)/j;
      pp += (double)i/j;
    }
    if (p <= pp)
      run = i, p = pp;
  }
  memset(bit, 0, sizeof bit);
  for (int i = 1; i < N; i++)
    upd(i, 1);
  ask(s);
  int cur = inf, bel = s;
  srand(time(0));
  set<int> st;
  int need = min(cnt - run, n), bneed = need, nn = n;
  while (need > 0 && nn > 0) {
    int id = (rand() * rand() % nn) + 1;
    id = get(id);
    assert(1 <= id && id <= n);
    st.insert(id);
    upd(id, -1);
    nn--; need--;
  }
  assert(bneed == st.size());

  for (int v : st) {
    ask(v);
    assert(val[v] >= 0);
    if (val[v] >= x)
      cur = min(cur, val[v]);
    else if (val[s] < val[v])
      s = v;
  }
  while (cnt > 0 && s > 0) {
    ask(s);
    assert(val[s] >= 0);
    if (val[s] >= x) {
      cur = min(cur, val[s]);
    }
    s = nxt[s];
  }
  assert(cur >= x);
  if (cur >= inf)
    cur = -1;
  ans(cur);
  return 0;
}