#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

void calc(int n, char s[N], int cnt[26]) {
  for (int i = 0; i < 26; ++i)
    cnt[i] = 0;
  for (int i = 0; i < n; ++i) {
    ++cnt[s[i]-'a'];
  }
}

char a[N], b[N];

int cnta[26], cntb[26];

void solve() {
  int n, k;
  scanf("%d %d", &n, &k);
  scanf("%s %s", a, b);
  calc(n, a, cnta);
  calc(n, b, cntb);
  int suma = 0, sumb = 0;
  for (int i = 0; i < 26; ++i) {
    suma += cnta[i];
    sumb += cntb[i];
    if (suma < sumb || ((suma-sumb) % k) != 0) {
      puts("No");
      return;
    }
  }
  puts("Yes");
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
