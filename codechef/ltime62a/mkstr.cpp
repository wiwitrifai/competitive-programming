// Wrong answer

#include <bits/stdc++.h>

using namespace std;

int mod[] = {int(1e9 + 8), int(1e9 + 9)};
int prime[] = {31, 37};

struct hashh {
  int v[2];
  hashh() {
    reset();
  }
  hashh operator=(hashh h) {
    for (int i = 0; i < 2; ++i)
      v[i] = h.v[i];
    return *this;
  } 
  bool operator==(hashh h) const {
    return v[0] == h.v[0] && v[1] == h.v[1];
  }
  void append(char c) {
    c -= 'a';
    for (int i = 0; i < 2; ++i) {
      v[i] = (1LL * v[i] * prime[i] + c) % mod[i];
    }
  }
  void reset() {
    memset(v, 0, sizeof v);
  }
};

const int N = 1024, M = 1e4, inf = 1e9 + 7;

hashh ht[N][N], hp[M];
char st[N], p[M][101];
int lenp[M];
int le[N][N], ri[N][N], lp = 0;
int cl[26], cr[26], kl[M], kr[M];

long long dp[N][N];

long long solve(int l, int r) {
  if (l > r) return 0;
  long long & ret = dp[l][r];
  if (ret != -1) return ret;
  ret = inf;
  for (int i = 1; i <= lp; ++i) {
    int ll = l+i;
    long long cur = solve(ll, r);
    int len = r-ll+1;
    ret = min(ret, cur + 1LL * len * le[l][ll-1]);
    if (ll > r) break;
  }
  for (int i = 1; i <= lp; ++i) {
    int rr = r-i;
    long long cur = solve(l, rr);
    int len = rr-l+1;
    ret = min(ret, cur + 1LL * len * ri[rr+1][r]);
    if (rr < l) break;
  }
  // cerr << l << " " << r << " = " << ret << endl;
  return ret;
}

int main() {
  int n;
  scanf("%d", &n);
  lp = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%s", p[i]);
    hp[i].reset();
    lenp[i] = strlen(p[i]);
    lp = max(lp, lenp[i]);
    for (int j = 0; j < lenp[i]; ++j)
      hp[i].append(p[i][j]);
  }
  for (int i = 0; i < 26; ++i) {
    scanf("%d", cl+i);
  }
  for (int i = 0; i < 26; ++i) {
    scanf("%d", cr+i);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", kl+i);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", kr+i);
  }
  scanf("%s", st);
  int len = strlen(st);
  for (int i = 0; i < len; ++i) {
    hashh cur;
    cur.reset();
    for (int j = i; j < len; ++j) {
      cur.append(st[j]);
      ht[i][j] = cur;
    }
  }
  for (int i = 0; i <= len; ++i)
    for (int j = 0; j <= len; ++j)
      le[i][j] = ri[i][j] = inf;
  for (int i = 0; i < len; ++i) {
    le[i][i] = min(le[i][i], cl[st[i]-'a']);
    ri[i][i] = min(ri[i][i], cr[st[i]-'a']);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0, k = lenp[i]-1; k < len; ++j, ++k)
      if (ht[j][k] == hp[i]) {
        le[j][k] = min(le[j][k], kl[i]);
        ri[j][k] = min(ri[j][k], kr[i]);
      }
  }
  // for (int i = 0; i < len; ++i)
  //   for (int j = i; j < len; ++j)
  //     cerr << " ri " << i << " " << j << " = " << ri[i][j] << endl;
  memset(dp, -1, sizeof dp);
  printf("%lld\n", solve(0, len-1));

  return 0;
}