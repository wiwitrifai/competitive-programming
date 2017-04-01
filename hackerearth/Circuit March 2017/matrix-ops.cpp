#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

int a[N][N];
int n, m;

int main() {
  vector< pair< int, int > > idx;
  scanf("%d %d", &n, &m);
  long long sum = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      scanf("%d", a[i]+j), idx.emplace_back(i, j), sum += a[i][j];
  sort(idx.begin(), idx.end(), [](pair< int, int > le, pair< int, int > ri) {
    long long ret = 1LL * (ri.first + 1) * (ri.second + 1) - 1LL * (le.first + 1) * (le.second + 1);
    if (ret != 0)
      return ret < 0;
    return le.first > ri.first;
  });
  sum -= n * n;
  for (auto it : idx) {
    long long cur = min(sum, m-1LL);
    a[it.first][it.second] = cur + 1;
    sum -= cur;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      printf("%d ", a[i][j]);
    printf("\n");
  }

  return 0;
}