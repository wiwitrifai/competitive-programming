#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 4;

char s[N];
int cnt[256];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int k, n;
    scanf("%s %d", s, &k);
    n = strlen(s);
    if (n % k) {
      puts("NO");
      continue;
    }
    memset(cnt, 0, sizeof cnt);
    for (int i = 0; i < n; i++)
      cnt[s[i]-'a']++;
    int ans = 0;
    for (int i = 0; i < 26; i++)
      ans += cnt[i]&1;
    int len = n/k;
    if (len & 1) {
      if (ans > k)
        puts("NO");
      else
        puts("YES");
    }
    else
      puts(ans ? "NO" : "YES");
  }
  return 0;
}