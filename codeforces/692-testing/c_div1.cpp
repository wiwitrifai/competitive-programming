#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char s[N];
int cnt[26];

int main() {
  int n;
  long long t;
  scanf("%d %lld", &n, &t);
  scanf("%s", s);
  t -= (1LL << (s[n-1] - 'a'));
  t += (1LL << (s[n-2] - 'a'));
  for (int i = 0; i < n-2; ++i) {
    int c = s[i] - 'a';
    ++cnt[c];
    t += (1LL << c);
  }
  if (t < 0) {
    puts("No");
    return 0;
  }
  for (int i = 25; i >= 0; --i) {
    long long cur = 1LL << (i+1);
    long long k = t / cur;
    if (k > cnt[i])
      k = cnt[i];
    t -= cur * k;
  }
  puts(t == 0 ? "Yes" : "No");
  return 0;
}
