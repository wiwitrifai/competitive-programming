#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 6;
int l[N], r[N], n;
int e[N];
vector<int> cek[N];

int main() {
  scanf("%d", &n);
  vector<int> v;
  for (int i = 0; i < n; i++) {
    scanf("%d %d", l+i, r+i);
    r[i]++; 
    v.push_back(l[i]);
    v.push_back(r[i]);
  }
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  for (int i = 0; i < n; i++) {
    l[i] = lower_bound(v.begin(), v.end(), l[i]) - v.begin();
    r[i] = lower_bound(v.begin(), v.end(), r[i]) - v.begin();
    e[l[i]]++;
    e[r[i]]--;
    cek[r[i]].push_back(i);
  }
  int last = 0, cur = 0, ans = -1;
  for (int i = 0; i < v.size(); i++) {
    for (int u : cek[i]) {
      if (last <= l[u])
        ans = u;
    }
    cur += e[i];
    if (cur < 2)
      last = i+1;
  }
  if (ans != -1) ans++;
  printf("%d\n", ans);
  return 0;
}