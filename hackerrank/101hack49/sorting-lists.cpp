#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int a[N], b[N], id[3 * N];
vector < int > v[3 * N];

bool cmp(int l, int r) {
  return v[l] < v[r];
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  vector< int > vx;
  for (int i = 0; i < n; i++) {
    scanf("%d %d", a+i, b+i);
    vx.push_back(a[i]);
    vx.push_back(b[i]);
  }
  sort(vx.begin(), vx.end());
  vx.erase(unique(vx.begin(), vx.end()), vx.end());
  for (int i = 0; i < n; i++) {
    a[i] = lower_bound(vx.begin(), vx.end(), a[i]) - vx.begin();
    b[i] = lower_bound(vx.begin(), vx.end(), b[i]) - vx.begin();
    for (int j = a[i]; j < b[i]; j++)
      v[j].push_back(i);
  }
  for (int i = 0; i < vx.size(); i++)
    id[i] = i;
  sort(id, id+vx.size(), cmp);
  int c = 0;
  while (v[id[c]].empty()) c++;
  while (--k > 0) {
    while (c < vx.size() && v[id[c]] == v[id[c+1]]) c++;
    c++;
  }
  c = id[c];
  printf("%d\n", v[c].size());
  for (int x : v[c])
    printf("%d ", x+1);
  printf("\n");
  return 0;
}