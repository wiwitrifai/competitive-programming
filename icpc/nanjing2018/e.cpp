#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

char s[N], t[N];

int n, k;
int flip[N];

int main() {
  scanf("%d %d %s %s", &n, &k, s, t);
  for (int i = 0; i < n; ++i)
    flip[i % k] ^= s[i] == '1';
  for (int i = 0; i < n; ++i)
    flip[i % k] ^= t[i] == '1';
  int ans = 0;
  if (flip[0])
    for (int i = 0; i < k; ++i)
      flip[i] ^= 1;
  for (int i = 0; i < k; ++i)
    ans |= flip[i];
  puts(!ans ? "Yes" : "No");
  return 0;
}