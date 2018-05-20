#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

long long s[N], ambil[N];
int a[N], b[N];
bool utang[N];

bool cek(int v, long long need) {
  if (utang[v]) return false;
  long long sisa = s[v] - ambil[v];
  if (sisa >= need) {
    ambil[v] += need;
    return true;
  }
  need -= sisa;
  ambil[v] += sisa;
  utang[v] = 1;
  bool res = cek(a[v], need);
  if (!res) return false;
  res = cek(b[v], need);
  utang[v] = 0;
  return res;
}

int main() {
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; ++tc) {
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; ++i)
      scanf("%d %d", a+i, b+i), --a[i], --b[i];
    for (int i = 0; i < m; ++i)
      scanf("%d", s+i);
    long long ans = 0;
    for (int i = 60; i >= 0; --i) {
      for (int j = 0; j < m; ++j)
        ambil[j] = 0, utang[j] = false;
      bool res = cek(0, 1LL<<i);
      if (res) {
        ans += 1LL << i;
        for (int j = 0; j < m; ++j) {
          s[j] -= ambil[j];
        }
      }
    }
    printf("Case #%d: %lld\n", tc, ans);
  }
  return 0;
}