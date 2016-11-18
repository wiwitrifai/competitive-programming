#include <bits/stdc++.h>

using namespace std;

const int N = 3005;
int a[N], b[N], ida[N], idb[N], tmp[N];
bool used[N];
vector< int > ansa, ansb;
int main() {
  int n, p, s;
  scanf("%d %d %d", &n, &p, &s);
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
    ida[i] = idb[i] = i;
  }
  for (int i = 0; i < n; i++)
    scanf("%d", b+i);
  sort(ida, ida+n, [](int x, int y) {
    return a[x] > a[y];
  });
  sort(idb, idb+n, [](int x, int y) {
    return b[x] > b[y];
  });
  int ans = 0;
  int suma = 0, sumb = 0;
  for (int i = 0; i < p; i++) {
    used[ida[i]] = 1;
    suma += a[ida[i]];
    ansa.push_back(ida[i]);
    tmp[i] = ida[i];
  }
  int cnt = 0;
  for (int j = 0; j < n; j++) {
    if (used[idb[j]])
      continue;
    ansb.push_back(idb[j]);
    sumb += b[idb[j]];
    cnt++;
    if (cnt == s)
      break;
  }
  ans = suma + sumb;
  for (int i = p; i < n; i++) {
    used[ida[i]] = 1;
    tmp[i] = ida[i];
    suma += a[ida[i]];
    cnt = i+1;
    if (cnt > s+p)
      break;
    sumb = 0;
    suma = 0;
    for (int j = 0; j <= i; j++) {
      tmp[j] = ida[j];
      suma += a[ida[j]];
    }
    for (int j = 0; j < n; j++) if (!used[idb[j]]) {
      if (cnt >= s+p)
        break;
      tmp[cnt++] = idb[j];
      sumb += a[idb[j]];
    }
    sort(tmp, tmp+s+p, [](int x, int y) {
      return b[x]-a[x] > b[y]-a[y];
    });
    for (int j = 0; j < s; j++)
      sumb += b[tmp[j]] - a[tmp[j]];
    if (suma + sumb > ans) {
      ans = suma + sumb;
      ansa.clear();
      ansb.clear();
      for (int j = 0; j < s; j++)
        ansb.push_back(tmp[j]);
      for (int j = s; j < s+p; j++)
        ansa.push_back(tmp[j]);
    }
  }
  printf("%d\n", ans);
  for (int i = 0; i < p; i++)
    printf("%d ", ansa[i]+1);
  printf("\n");
  for (int i = 0; i < s; i++)
    printf("%d ", ansb[i]+1);
  printf("\n");
  return 0;
}