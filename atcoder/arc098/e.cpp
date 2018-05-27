#include <bits/stdc++.h>

using namespace std;

const int N = 2018;

int a[N];

int main() {
  int n, k, q;
  scanf("%d %d %d", &n, &k, &q);
  vector<int> va;
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i), va.push_back(a[i]);
  sort(va.begin(), va.end());
  va.erase(unique(va.begin(), va.end()), va.end());
  int ans = va.back() - va[0];
  for (int mi : va) {
    vector<int> pq;
    int j = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] < mi) {
        if (j < i && i-j >= k) {
          vector<int> now;
          for (int z = j; z < i; ++z) {
            now.push_back(a[z]);
          }
          sort(now.begin(), now.end());
          for (int z = 0; z <= i-j-k; ++z)
            pq.push_back(now[z]);
        }
        j = i+1;
      }
    }
    if (j < n && n-j >= k) {
      vector<int> now;
      for (int z = j; z < n; ++z) {
        now.push_back(a[z]);
      }
      sort(now.begin(), now.end());
      for (int z = 0; z <= n-j-k; ++z)
        pq.push_back(now[z]);
    }
    if (pq.size() >= q) {
      sort(pq.begin(), pq.end());
      ans = min(ans, pq[q-1] - pq[0]);
    }
  }
  printf("%d\n", ans);
  return 0;
}