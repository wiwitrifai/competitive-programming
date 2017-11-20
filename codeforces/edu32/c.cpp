#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 4;

char s[N];
int n;
bool ada[30];
int cnt[30];

bool can(int k) {
  memset(cnt, 0, sizeof cnt);
  for (int i = 0; i < 26; i++)
    ada[i] = 1;
  for (int i = 0; i < n; i++) {
    cnt[s[i]]++;
    if (i >= k)
      cnt[s[i-k]]--;
    if (i >= k-1) {
      for (int j = 0; j < 26; j++)
        ada[j] &= cnt[j] > 0;
    }
  }
  bool ok = 0;
  for (int i = 0; i < 26; i++)
    ok |= ada[i];
  return ok;
}
int main() {
  scanf("%s", s);
  n = strlen(s);
  for (int i = 0; i < n; i++)
    s[i] -= 'a';
  int l = 1, r = n;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (can(mid))
      r = mid;
    else
      l = mid + 1;
  }
  printf("%d\n", r);
  return 0;
}