#include <bits/stdc++.h>

using namespace std;

const int N = 2018;

int a[N];
int sl[N], dl[N], sr[N], dr[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i);
  sl[0] = dl[0] = 0;
  for (int i = 0; i < n; ++i) {
    if (i)
      sl[i] = sl[i-1], dl[i] = dl[i-1];
    if (a[i] == 1)
      ++sl[i];
    else
      dl[i] = max(sl[i], dl[i]) + 1;
    dl[i] = max(dl[i], sl[i]);
  }
  sr[n-1] = dr[n-1] = 0;
  for (int i = n-1; i >= 0; --i) {
    if (i < n-1)
      sr[i] = sr[i+1], dr[i] = dr[i+1];
    if (a[i] == 2)
      ++dr[i];
    else
      sr[i] = max(sr[i], dr[i]) + 1;
    sr[i] = max(dr[i], sr[i]);
  }
  int ans = max(dl[n-1], sl[n-1]);
  for (int i = 0; i < n; ++i) {
    int dm = 0, sm = 0, satu = 0, dua = 0;
    int slnow = 0, dlnow = 0;
    if (i)
      slnow = sl[i-1], dlnow = dl[i-1];
    for (int j = i; j < n; ++j) {
      if (a[j] == 2)
        ++dm, ++dua;
      else
        ++sm, ++satu;
      sm = max(sm, dm);
      ans = max(ans, slnow + satu + sr[j+1]);
      ans = max(ans, slnow + sm + dr[j+1]);
      ans = max(ans, slnow + dm + dr[j+1]);
      ans = max(ans, dlnow + dm + dr[j+1]);
    }
  }
  printf("%d\n", ans);
  return 0;
}