#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char s[N];
int cnt[55];
int main() {
  scanf("%s", s);
  int n = strlen(s);
  for (int i = 0; i < n; i++)
    cnt[s[i]-'a']++;
  long long cur = -1, ans = -1;
  for (int x = 2; x <= n + 100; x++) {
    long long now = 0;
    for (int i = 0; i < 26; i++) {
      now += 1LL * (cnt[i] % x) * cnt[i];
    }
    if (ans == -1 || now < cur) {
      ans = x;
      cur = now;
    }
  }
  cout << ans << endl;
  return 0;
}