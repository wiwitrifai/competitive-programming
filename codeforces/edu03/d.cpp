#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, inf = 1e9;

int n, m, k, s;
int a[N], b[N], na[N], nb[N], ndol, npon;

pair< int, int > dol[N], pon[N];

int main() {
  scanf("%d%d%d%d", &n, &m, &k, &s);
  a[0] = b[0] = inf;
  for(int i = 1; i<=n; i++) {
    scanf("%d", a+i);
    na[i] = (a[i] >= a[na[i-1]]) ? na[i-1] : i;
  }
  for(int i = 1; i<=n; i++) {
    scanf("%d", b+i);
    nb[i] = (b[i] >= b[nb[i-1]]) ? nb[i-1] : i;
  }
  ndol = npon = 0;
  for(int i = 1; i<=m; i++) {
    int t, c;
    scanf("%d%d", &t, &c);
    if(t == 1)
      dol[ndol++] = make_pair(c, i);
    else
      pon[npon++] = make_pair(c, i);
  }
  sort(dol, dol + ndol);
  sort(pon, pon + npon);
  int l = 0, r = n+1;
  while(l < r) {
    int mid = (l+r) >> 1, cnt = 0, idol, ipon;
    bool ok = true;
    long long cost = 0;
    idol = ipon = 0;
    while(cnt < k) {
      if(idol < ndol && ipon < npon) {
        if(1LL*dol[idol].first*a[na[mid]] < 1LL*pon[ipon].first*b[nb[mid]]) {
          cost += 1LL*dol[idol].first*a[na[mid]];
          idol++;
        }
        else {
          cost += 1LL*pon[ipon].first*b[nb[mid]];
          ipon++;
        }
      }
      else if(idol < ndol) {
        cost += 1LL*dol[idol].first*a[na[mid]];
        idol++;
      }
      else if(ipon < npon) {
        cost += 1LL*pon[ipon].first*b[nb[mid]];
        ipon++;
      }
      else
        assert(false);
      cnt++;
      if(cost > s) {
        ok = false;
        break;
      }
    }
    if(ok)
      r = mid;
    else
      l = mid + 1;
  }
  if(l <= 0 || l > n) {
    puts("-1");
    return 0;
  }
  vector< pair< int, int > > ans;
  long long cost = 0;
  int mid = l, idol, ipon;
  idol = ipon = 0;
  for(int i = 0; i<k; i++) {
    if(idol < ndol && ipon < npon) {
      if(1LL*dol[idol].first*a[na[mid]] < 1LL*pon[ipon].first*b[nb[mid]]) {
        cost += 1LL*dol[idol].first*a[na[mid]];
        ans.emplace_back(dol[idol].second, na[mid]);
        idol++;
      }
      else {
        cost += 1LL*pon[ipon].first*b[nb[mid]];
        ans.emplace_back(pon[ipon].second, nb[mid]);
        ipon++;
      }
    }
    else if(idol < ndol) {
      cost += 1LL*dol[idol].first*a[na[mid]];
      ans.emplace_back(dol[idol].second, na[mid]);
      idol++;
    }
    else if(ipon < npon) {
      cost += 1LL*pon[ipon].first*b[nb[mid]];
      ans.emplace_back(pon[ipon].second, nb[mid]);
      ipon++;
    }
  }
  printf("%d\n", l);
  sort(ans.begin(), ans.end());
  for(int i = 0; i<ans.size(); i++) {
    printf("%d %d\n", ans[i].first, ans[i].second);
  }
  return 0;
}