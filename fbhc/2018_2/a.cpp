#include <bits/stdc++.h>

using namespace std;

int node[101];

int main() {
  clock_t startt = clock();
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; ++tc) {
    int n, k;
    scanf("%d %d", &n, &k);
    if (n <= 2 || k <= 2) {
      printf("Case #%d: %d\n", tc, 0);
      printf("%d\n%d %d %d\n", 1, 1, n, 1);
      continue;
    }
    int s = min(n, k);
    int sum = (s-1) * (k-1 + (k - s+1)) / 2;
    int ans = sum - k;
    node[0] = 1;
    node[s-1] = n;
    for (int j = 1; j < s-1; ++j)
      node[j] = j+1;
    printf("Case #%d: %d\n", tc, ans);
    int cnt = s-1;
    cnt += s > 2;
    printf("%d\n", cnt);
    for (int j = 0; j+1 < s; ++j) {
      printf("%d %d %d\n", node[j], node[j+1], k-1-j);
    }
    if (s > 2)
      printf("%d %d %d\n", 1, n, k);
    cerr << " TC# " << tc << " done ! time : " << (double)(clock() - startt) / CLOCKS_PER_SEC << " s " << endl;
  }
  return 0;
}