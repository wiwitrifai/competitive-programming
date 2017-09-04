#include <bits/stdc++.h>

using namespace std;

const int N = 30;

map<int, int> mp;
map<int, set<int>> st;
map<int, int> g;
int get(int mask) {
  auto it = g.find(mask);
  if (it != g.end())
    return it->second;
  for (int j = 0; j < N; j++) {
    int k = (mask >> (j+1)) | (((1<<j)-1) & mask);
    if (k < mask)
      st[mask].insert(get(k));
  }
  int ret = 0;
  set<int> &cur = st[mask];
  for (int x : cur)
    ret += ret == x;
  return g[mask] = ret;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    for (int j= 2; 1LL * j * j <= a; j++) if ((a % j) == 0) {
      int k = 0;
      while ((a % j) == 0) {
        a /= j;
        k++;
      }
      mp[j] |= 1<<(k-1);
    }
    if (a > 1)
      mp[a] |= 1;
  }
  int ans = 0;
  for (auto it : mp)
    ans ^= get(it.second);
  puts(ans ? "Mojtaba" : "Arpa");
  return 0;
}