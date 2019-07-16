#include <bits/stdc++.h>

using namespace std;

const int N = 5202;
bitset<N> bs[N];

char s[N];
int gcd(int x, int y) {
  return x ? gcd(y % x, x) : y;
}

int mp[256];

int main() {
  memset(mp, -1, sizeof mp);
  for (int i = 0; i < 10; ++i)
    mp['0' + i] = i;
  for (char i = 'A'; i <= 'F'; ++i)
    mp[i] = i - 'A' + 10;
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s", s);
    int len = strlen(s);
    assert(len * 4 == n);
    for (int j = 0; j < len; ++j) {
      int now = mp[s[j]];
      assert(now >= 0 && now <= 15);
      for (int k = 3; k >= 0; --k) {
        bs[i][j * 4 + k] = now & 1;
        now /= 2;
      }
    }
  }
  int ans = n;
  for (int i = 0; i < n; ++i) {
    int cnt = 0;
    int cur = 0;
    for (int j = 0; j < n; ++j) {
      if (bs[i][j] != cur) {
        ans = gcd(ans, cnt);
        cur = bs[i][j];
        cnt = 0;
      }
      ++cnt;
    }
    ans = gcd(ans, cnt);
  }
  for (int j = 0; j < n; ++j) {
    int cnt = 0;
    int cur = 0;
    for (int i = 0; i < n; ++i) {
      if (bs[i][j] != cur) {
        ans = gcd(ans, cnt);
        cur = bs[i][j];
        cnt = 0;
      }
      ++cnt;
    }
    ans = gcd(ans, cnt);
  }
  printf("%d\n", ans);
  return 0;
}