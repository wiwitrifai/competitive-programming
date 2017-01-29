#include <bits/stdc++.h>

using namespace std;

char s[50];

const int mod = 1e9 + 7;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
  int a, b, k;
  scanf("%s", s);
  int n = strlen(s);
  a = 0;
  for (int i = 0; i < n; i++) {
    a <<= 1;
    a += s[i] - '0';
  }
  scanf("%s", s);
  n = strlen(s);
  b = 0;
  for (int i = 0; i < n; i++) {
    b <<= 1;
    b += s[i] - '0';
  }
  int ccnt[50];
  scanf("%d", &k);
  int ans = 0;
  memset(ccnt, 0, sizeof ccnt);
  for (int i = 1; i <= b; i++) {
    int now = i;
    int cnt = 0;
    while (now & (now-1)) {
      cnt++;
      now += now & (-now);
    }
    if (cnt == k) {
      ans++;
      // int x = i;
      // int y = b;
      // int id = n+1;
      // while (x != y) {
      //   x >>= 1;
      //   y >>= 1;
      //   id--;
      // }
      // assert(id >= 0);
      // ccnt[id]++;
    }
  }
  // cerr << b << "b"<< endl;
  // for (int i = 0; i <= n; i++)
  //   cerr << ccnt[i] << endl;
  // cerr << ans << endl;

  int tmp = 0;
  for (int i = 1; i < a; i++) {
    int now = i;
    int cnt = 0;
    while (now & (now-1)) {
      cnt++;
      now += now & (-now);
    }
    if (cnt == k)
      tmp++;
  }
  // cerr << ans << " " << tmp << endl;
  ans -= tmp;
  ans %= mod;
  if (ans < 0)
    ans += mod;
  cout << ans << endl;
}
  return 0;
}