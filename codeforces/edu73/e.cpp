#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

char s[N];

void solve() {
  int a, b;
  scanf("%d %d", &a, &b);
  scanf("%s", s);
  int n = strlen(s);
  int cnt = 0;
  vector<int> len;
  s[n] = 'X';
  for (int i = 0; i <= n; ++i) {
    if (s[i] == 'X') {
      if (cnt >= b)
        len.push_back(cnt);
      cnt = 0;
    }
    else {
      ++cnt;
    }
  }
  sort(len.begin(), len.end());
  if (len.empty()) {
    puts("NO");
    return;
  }
  if (len[0] < a) {
    puts("NO");
    return;
  }
  int sz = len.size();
  if (len.size() >= 2 && len[sz-2] >= 2 * b) {
    puts("NO");
    return;
  }
  int last = len.back();
  for (int i = 0; i + a <= last; ++i) {
    int lef = i, rig = last - i - a;
    if (lef >= b && lef < a) continue;
    if (rig >= b && rig < a) continue;
    if (lef >= 2 * b || rig >= 2 * b) continue;
    int cnt = sz - 1 + (lef >= a) + (rig >= a);
    if ((cnt & 1) == 0) {
      puts("YES");
      return;
    }
  }
  puts("NO");
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
