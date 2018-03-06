#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

char s[N];
int cnt[10];

bool solve(int n) {
  int cur = 0;
  for (int k = 1; k <= n; ++k) {
    if (cur >= 10) break;
    if (s[n-k] == '0') continue;
    ++cur;
    memset(cnt, 0, sizeof cnt);
    for (int i = 0; i < n-k; ++i)
      cnt[s[i]-'0'] ^= 1;
    int ganjil = 0;
    for (int i = 0; i < 10; ++i) {
      ganjil += cnt[i] & 1;
    }
    if (ganjil > k) continue;
    if (ganjil == k) {
      int cari = -1;
      for (int j = s[n-k]-'0'-1; j >= 0; --j) {
        if (cnt[j] & 1) {
          cari = j;
          break;
        }
      }
      if (cari == -1) continue;
      s[n-k] = cari + '0';
      cnt[cari] ^= 1;
    }
    else {
      --s[n-k];
      cnt[s[n-k]-'0'] ^= 1;
    }
    for (int i = n-1; i > n-k; --i) {
      int cari = -1;
      for (int j = 0; j < 10; ++j)
        if (cnt[j] & 1) {
          cari = j;
          break;
        }
      if (cari == -1)
        cari = 9;
      cnt[cari]^= 1;
      s[i] = cari + '0';
    }
    if (s[0] == '0') return 0;
    printf("%s\n", s);
    return 1;
  }
  return 0;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", s);
    int n = strlen(s);
    assert((n & 1) == 0);
    if (!solve(n)) {
      for (int i = 2; i < n; ++i)
        printf("9");
      printf("\n");
    }
  }
  return 0;
}