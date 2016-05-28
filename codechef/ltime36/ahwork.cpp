#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
const int inf = 1e8 + 5;

int n;
char s[N][5];
int dp[N][N][5];
int type[N];
int to[7][7][5], tto[7][5];
char tl[][5] = {"", "a", "b", "", ""},
  tr[][5] = {"", "", "", "a", "b"};
int cmp(char *a, char *b, char *c, char *d) {
  int na = strlen(a), nb = strlen(b), nc = strlen(c), nd = strlen(d);
  int llen = na + nb, rlen = nc + nd;
  char sl[10], sr[10];
  strcpy(sl, a);//, na * sizeof(char));
  strcpy(sl+na, b);//, nb * sizeof(char));
  strcpy(sr, c);//, nc * sizeof(char));
  strcpy(sr+nc, d);//, nd * sizeof(char));
  sl[llen] = sr[rlen] = '\0';
  int id = 0;
  while(id < llen && id < rlen) {
    if(sl[id] == sr[rlen-id-1])
      id++;
    else
      break;
  }
  // cout << sl << " " << sr << " = ";
  int tmpl = llen-id, tmpr = rlen-id; 
  if(tmpl + tmpr > 1)
    return -1;
  if(tmpl == 0 && tmpr == 0)
    return 0;
  if(tmpl)
    return 1 + (sl[llen-1] == 'b');
  if(tmpr)
    return 3 + (sr[0] == 'b');
}

int solve(int l, int r, int t) {
  if(l > r)
    return 0;
  if(l == r) {
    if(t == 0) {
      if(s[l][1] == '\0')
        return 0;
      else
        return s[l][0] != s[l][1];
    }
    else {
      return (to[type[l]][6][t] >= 0 || to[6][type[l]][t] >= 0) ? 0 : 1;
    }
  }
  int & ret = dp[l][r][t];
  if(ret >= 0)
    return ret;
  ret = min(solve(l, r-1, t), solve(l+1, r, t)) + 1;
  int tt = to[type[l]][type[r]][t];
  if(tt >= 0)
    ret = min(ret, solve(l+1, r-1, tt));
  tt = to[type[l]][6][t];
  if(tt >= 0)
    ret = min(ret, solve(l+1, r, tt));
  tt = to[6][type[r]][t];
  if(tt >= 0)
    ret = min(ret, solve(l, r-1, tt));
  // cout << l << " " << r << " " << t << " = " << to[type[l]][type[r]][t] << " - " << ret << endl;
  return ret;
}
char ttype[][5] = {"a", "b", "aa", "bb", "ab", "ba", ""};

int main() {
  for(int i = 0; i<=6; i++)
    for(int j = 0; j<=6; j++)
      for(int tt = 0; tt < 5; tt++) {
        to[i][j][tt] = cmp(tl[tt], ttype[i], ttype[j], tr[tt]);
        // cout << to[i][j][tt] << endl;
      }
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%d", &n);
    for(int i = 0; i<n; i++) {
      scanf("%s", s[i]);
      if(strcmp(s[i], "a") == 0)
        type[i] = 0;
      else if(strcmp(s[i], "b") == 0)
        type[i] = 1;
      else if(strcmp(s[i], "aa") == 0)
        type[i] = 2;
      else if(strcmp(s[i], "bb") == 0)
        type[i] = 3;
      else if(strcmp(s[i], "ab") == 0)
        type[i] = 4;
      else if(strcmp(s[i], "ba") == 0)
        type[i] = 5;
      // cerr << i << " " << type[i] << endl;
    }
    memset(dp, -1, sizeof dp);
    printf("%d\n", solve(0, n-1, 0));
  }

  return 0;
}