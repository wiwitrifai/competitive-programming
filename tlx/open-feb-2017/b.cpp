#include <bits/stdc++.h>

using namespace std;

const int N = 155;

long long s[N], a[N], b[N];
int ul[N], ur[N], id[N];
int n, m, pos[N];

bool cek(long long x) {
  memset(ul, 0, sizeof ul);
  memset(ur, 0, sizeof ur);
  for (int z = 0; z < n; z++) {
    int le = -1, ri = -1;
    int i = id[z];
    for (int j = 0; j < n; j++) {
      if (j == i) continue;
      if (abs(s[i] - s[j]) > x) continue; 
      if (b[j] <= a[i] && !ur[j]) {
        if (le == -1 || pos[j] < pos[le])
          le = j;
      }
      if (a[j] >= b[i] && !ul[j]) {
        if (ri == -1 || pos[j] < pos[ri])
          ri = j;
      }
    }
    if (le != -1) {
      ul[i] = 1;
      ur[le] = 1;
    }
    if (ri != -1) {
      ur[i] = 1;
      ul[ri] = 1;
    }
  }
  int cnt = 0;
  for (int i = 0; i < n; i++)
    cnt += ul[i] == 0;
  return cnt <= m;
}
bool cmp(int le, int ri) {
  return s[le] > s[ri];
}

int main() {
  scanf("%d %d", &n, &m);
  long long l = 0, r = 0;
  for (int i = 0;i < n; i++) {
    scanf("%lld %lld %lld", s+i, a+i, b+i);
    r = max(r, s[i]);
    id[i] = i;
  }
  sort(id, id+n, cmp);
  for (int i = 0; i < n; i++)
    pos[id[i]] = i;
  while (l < r) {
    long long mid = (l + r) / 2;
    if (cek(mid))
      r = mid;
    else
      l = mid+1;
  }
  if (!cek(l)) {
    puts("-1");
  }
  else
    printf("%lld\n", l);
  return 0;
}