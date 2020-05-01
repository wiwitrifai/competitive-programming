#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
    }
    vector<int> b = a;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    if (b.size() > k) {
      puts("-1");
      continue;
    }
    while (b.size() < k) b.push_back(b.back());
    printf("%d\n", (int)k * n);
    for (int i = 0; i < n * k; ++i) {
      printf("%d%c", b[i % k], i +1 == n * k ? '\n' : ' ');
    }
  }
  return 0;
}
