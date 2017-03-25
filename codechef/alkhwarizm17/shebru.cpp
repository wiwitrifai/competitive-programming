#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6, mod = 1e9 + 7;
char s[N];
int bit[2][N], m;
void upd(int id, int x, int val) {
  for (; x < N; x += x&(-x)) {
    bit[id][x] += val;
    if (bit[id][x] >= mod)
      bit[id][x] -= mod;
  }
}
int get(int id, int x) {
  int ret = 0;
  for (; x; x -= x&(-x)) {
    ret += bit[id][x];
    if (ret >= mod) ret -= mod;
  }
  return ret;
}
vector< int > x[26];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", s);
    x[s[0]-'a'].push_back(strlen(s));
  }
  long long ans = 0;
  for (int i = 0; i < 26; i++) {
    memset(bit, 0, sizeof bit);
    for (int v : x[i]) {
      // cerr << v << " ";
      int gu = v ? get(0, v-1) : 0, gd = get(1, N-1-v-1);
      ans += gu + gd;
      while (ans >= mod) ans -= mod;
      upd(1, N-1-v, gu+1);
      upd(0, v, gd+1);
    }
    // cerr << i << endl;
  }
  printf("%d\n", ans);

  return 0;
}