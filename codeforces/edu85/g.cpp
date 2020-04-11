#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int p[26], q[26];

char s[N], t[N];
bitset<N> bs[26], ans;

int main() {
  for (int i = 0; i < 26; ++i) {
    scanf("%d", p+i);
    --p[i];
    q[p[i]] = i;
  }
  scanf("%s %s", s, t);
  int m = strlen(s), n = strlen(t);
  for (int i = 0; i < n; ++i) {
    int c = t[i] - 'a';
    bs[c][i] = 1;
    bs[q[c]][i] = 1;
  }
  for (int i = 0; i <= n-m; ++i)
    ans[i] = 1;
  for (int i = 0; i < m; ++i) {
    int c = s[i] - 'a';
    ans &= bs[c] >> i;
  }
  for (int i = 0; i <= n-m; ++i)
    printf("%d", (int)ans[i]);
  printf("\n");
  return 0;
}
