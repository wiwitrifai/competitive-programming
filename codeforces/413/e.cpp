#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 6;

int c[N];
bool a[N], b[N];
bool used[N];

vector< pair< int, int > > va, vb;

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < n; i++)
    scanf("%d", c+i);
  int z;
  scanf("%d", &z);
  while (z--) {
    int x;
    scanf("%d", &x); x--;
    a[x] = 1;
    va.emplace_back(c[x], x);
  }
  scanf("%d", &z);
  while (z--) {
    int x;
    scanf("%d", &x); x--;
    b[x] = 1;
    vb.emplace_back(c[x], x);
  }
  int both = 0, oa = 0, ob = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] && b[i]) both++;
    else if (a[i]) oa++;
    else if (b[i]) ob++;
  }
  if (min(min(oa, ob), (m-both)/2) + both < k || va.size() < k || vb.size() < k) {
    puts("-1");
    return 0;
  }
  sort(va.begin(), va.end());
  sort(vb.begin(), vb.end());
  set< int > st;
  for (int i = 0; i < k; i++) {
    st.insert(va[i].second);
    st.insert(vb[i].second);
    used[va[i].second] = 1;
    used[vb[i].second] = 1;
  }
  long long ans = -1;
  long long now = 0;
  int bb = 0;
  int oo = 0;
  set< pair< int, int > > sa, sb, sab, so;
  bb = 0;
  for (auto it : st) {
    now += c[it];
    if (a[it] && b[it]) bb++;
    else if (a[it])
      sa.insert(make_pair(-c[it], it));
    else if (b[it])
      sb.insert(make_pair(-c[it], it));
    else oo++;
  }
  for (int i = 0; i < n; i++)
    if (a[i] && b[i] && !used[i])
      sab.insert(make_pair(c[i], i));
    else if (!used[i])
      so.insert(make_pair(c[i], i));
  while ((bb + sa.size() + sb.size() + oo) < m && (so.size() > 0 || sab.size() > 0)) {
    if (sab.empty()) {
      auto it = so.begin();
      now += it->first;
      so.erase(it);    
      oo++;
    }
    else if (so.empty()) {
      auto it = sab.begin();
      now += it->first;
      sab.erase(it);    
      bb++;
    }
    else {
      auto it = so.begin();
      auto it2 = sab.begin();
      if (it->first < it2->first) {
        now += it->first;
        so.erase(it);
        oo++;
      }
      else {
        now += it2->first;
        sab.erase(it2);    
        bb++;
      }
    }
  }
  while ((bb + sa.size() + sb.size() + oo) > m) {
    if (sa.size() > sb.size()) {
      if (sa.empty()) break;
       auto it = sa.begin();
       now += it->first;
       sa.erase(it);
    }
    else {
      if (sb.empty()) break;
       auto it = sb.begin();
       now += it->first;
       sb.erase(it);
    }
    while (((sa.size() + bb) < k || (sb.size() + bb) < k) && sab.size() > 0) {
      auto it = sab.begin();
      now += it->first;
      sab.erase(it);
      bb++;
    }
  }
  if ((bb + sa.size() + sb.size() + oo) == m)
    ans = now;
  while ((sa.size() + sb.size()) > 0) {
    if (sa.size() > sb.size()) {
       auto it = sa.begin();
       now += it->first;
       sa.erase(it);
    }
    else {
       auto it = sb.begin();
       now += it->first;
       sb.erase(it);
    }
    if ((sa.size() + bb) < k || (sb.size() + bb) < k) {
      if (sab.empty()) break;
      auto it = sab.begin();
      now += it->first;
      sab.erase(it);
      bb++;
    }
    if ((sa.size() + bb) < k || (sb.size() + bb) < k)
      break;
    while ((sa.size() + bb + sb.size() + oo) < m && so.size() > 0) {
      auto it = so.begin();
      now += it->first;
      so.erase(it);
      oo++;
    }
    if ((sa.size() + bb + sb.size() + oo) == m)
      ans = min(ans, now);
  }
  cout << ans << endl;
  return 0;
}