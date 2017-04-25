#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int a[N], b[N], p[N], q[N];

bool cmpA(int l, int r) {
  if (a[l] != a[r])
    return a[l] > a[r];
  return b[l] > b[r];
}
bool cmpB(int l, int r) {
  if (b[l] != b[r])
    return b[l] > b[r];
  return a[l] > a[r];
}

int main() {
  int n;
  scanf("%d", &n);
  long long totA = 0, totB = 0;
  for (int i = 0; i < n; i++)
    scanf("%d", a+i), totA += a[i];
  for (int i = 0; i < n; i++)
    scanf("%d", b+i), totB += b[i];
  for (int i = 0; i < n; i++)
    p[i] = q[i] = i;
  sort(p, p+n, cmpA);
  sort(q, q+n, cmpB);
  int ip = 0, iq = 0;
  set< int > ans;
  int s = n;
  set< int > sA, sB;
  set< pair< int, int > > ssA, ssB;
  int need = n/2 + 1;
  while (ans.size() < need) {
    int to = s/2 + 1;
    while (sA.size() < to) {
      if (sB.count(p[ip])) {
        ssA.insert(make_pair(-a[p[ip]], p[ip]));
        ssB.insert(make_pair(-b[p[ip]], p[ip]));
      }
      sA.insert(p[ip]);
      ip++;
    }
    while (sB.size() < to) {
      if (sA.count(q[iq])) {
        ssA.insert(make_pair(-a[q[iq]], q[iq]));
        ssB.insert(make_pair(-b[q[iq]], q[iq]));
      }
      sB.insert(q[iq]);
      iq++;
    }
    while (ans.size() < need && !ss.empty()) {
      auto it = ss.begin();
      ans.insert(*it);
      ss.erase(it);
      sA.erase(*it);
      sB.erase(*it);
    }
  }
  printf("%d\n", ans.size());
  long long sumA = 0, sumB = 0;
  for (int id : ans)
    printf("%d ", id+1), sumA += a[id], sumB += b[id];
  printf("\n");
  assert(2LL * sumA > totA && 2LL * sumB > totB);
  return 0;
}