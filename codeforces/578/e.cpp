#include <bits/stdc++.h>

using namespace std;

int pr[5] = {83, 89, 97, 101, 103};
const int mod[2] = {int(1e9 + 7), int(1e9+9)};
const int N = 1e6 + 5;
char ans[N];
char s[N];

int enc(char c) {
  if ('0' <= c && c <= '9')
    return c - '0';
  if ('a' <= c && c <= 'z')
    return 11 + (c - 'a');
  return 38 + (c - 'A');
}

int main() {
  srand(time(0));
  random_shuffle(pr, pr+5);
  int len = 0;
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s", s);
    int m = strlen(s);
    int same = 0;
    int iter = min(m, len);
    int val[2];
    val[0] = val[1] = 1;
    int lef[2], rig[2];
    memset(lef, 0, sizeof lef);
    memset(rig, 0, sizeof rig);
    for (int j = 0; j < iter; ++j) {
      int now = enc(ans[len-1-j]), nxt = enc(s[j]);
      for (int k = 0; k < 2; ++k) {
        lef[k] = (1LL * lef[k] * pr[k] + now) % mod[k];
        rig[k] = (rig[k] + 1LL * nxt * val[k]) % mod[k];
        val[k] = 1LL * val[k] * pr[k] % mod[k];
      }
      if (lef[0] == rig[0] && lef[1] == rig[1]) {
        same = j+1;
      }
    }
    for (int j = same; j < m; ++j)
      ans[len++] = s[j];
  }
  ans[len] = 0;
  printf("%s\n", ans);
  return 0;
}
