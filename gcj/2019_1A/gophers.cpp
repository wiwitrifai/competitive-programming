#include <bits/stdc++.h>

using namespace std;

const int W = 18;
vector<int> mod = {17, 16, 5, 9, 7, 11, 13};

int ask(int x) {
  for (int i = 0; i < W; ++i) {
    printf("%d%c", x, i == W-1 ? '\n' : ' ');
  }
  fflush(stdout);
  int ret = 0;
  for (int i = 0; i < W; ++i) {
    int v;
    scanf("%d", &v);
    if (v < 0)
      return -1;
    ret = (ret + v) % x;
  }
  return ret;
}

long long extended_euclid(long long a, long long b, long long &x, long long &y) {
  if(b == 0) { x = 1; y = 0; return a; }
  long long d = extended_euclid(b, a % b, x, y);
  long long xx, yy;
  xx = y;
  yy = x - (a/b)*y;
  x = xx; y = yy;
  return d;
}

pair<long long, long long> chinese_remainder_theorem(long long x, long long a, long long y, long long b){
  long long s, t;
  long long d = extended_euclid(x, y, s, t);
  if(a%d != b%d)return make_pair(0,-1);
  return make_pair(((s*b*x+t*a*y) % (x*y))/d, x*y/d);
}

bool solve() {
  vector<pair<int, int> > crt;
  for (int m : mod) {
    int ret = ask(m);
    if (ret < 0)
      return -1;
    crt.emplace_back(ret, m);
  }
  pair<long long, long long> ans = crt[0];
  for (int i = 1; i < crt.size(); ++i) {
    ans = chinese_remainder_theorem(ans.second, ans.first, crt[i].second, crt[i].first);
  }

  ans.first %= ans.second;
  if (ans.first < 0)
    ans.first += ans.second;
  printf("%lld\n", ans.first);
  fflush(stdout);
  int result;
  scanf("%d", &result);
  return result > 0;
}

int main() {
  int t, n, m;
  scanf("%d %d %d", &t, &n, &m);
  while (t--) {
    if (!solve())
      break;
  }
  return 0;
}
