#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

char s[N], t[N];
int f[N], rig[N];
int n;

int calc(int maxi) {
  int add = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] != '?') continue;
    if (rig[i+1] + (add + 1) * 2 <= maxi) {
      ++add;
      s[i] = '1';
    }
    else {
      s[i] = '0';
    }
  }
  int now = 0, low = 0, hig = 0;
  for (int i = 0; i < n; ++i) {
    now += (s[i] == '1' ? 1 : -1);
    low = min(low, now);
    hig = max(hig, now);
  }
  return abs(hig - low);
}

int main() {
  scanf("%s", s);
  n = strlen(s);
  f[0] = 0;
  int maxi = 0;
  for (int i = 0; i < n; ++i) {
    f[i+1] = f[i] + (s[i] == '1') * 2 - 1;
    maxi = max(maxi, f[i+1]);
  }
  rig[n] = f[n];
  for (int i = n-1; i >= 0; --i) {
    rig[i] = max(rig[i+1], f[i]);
  }
  for (int i = 0; i < n; ++i)
    t[i] = s[i];
  int ans = calc(maxi);
  for (int i = 0; i < n; ++i)
    s[i] = t[i];
  ans = min(ans, calc(maxi+1));
  for (int i = 0; i < n; ++i)
    s[i] = t[i];
  ans = min(ans, calc(maxi+2));
  printf("%d\n", ans);
  return 0;
}
