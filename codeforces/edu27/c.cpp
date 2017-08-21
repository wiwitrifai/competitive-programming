#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int l[N], r[N], id[N];

bool used[N];

bool cmp(int le, int ri) {
  if (l[le] != l[ri])
    return l[le] < l[ri];
  return r[le] < r[ri];
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", l+i, r+i);
    id[i] = i;
  }
  sort(id, id+n, cmp);
  int now = -1;
  for (int i = 0; i < n; i++) {
    if (l[id[i]] > now) {
      used[id[i]] = 1;
      now = r[id[i]];
    }
  }
  bool ok = 1;
  now = -1;
  for (int i = 0; i < n; i++) {
    if (!used[id[i]]) {
      if (now >= l[id[i]])
        ok = 0;
      now = r[id[i]];
    }
  }
  puts(ok ? "YES" : "NO");
  return 0;
}