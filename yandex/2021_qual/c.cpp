#include <bits/stdc++.h>

using namespace std;

int main() {
  int k;
  scanf("%d", &k);
  vector<int> a(k), b(k);
  int maxi = 0, sum = 0;
  for (int i = 0; i < k; ++i) {
    scanf("%d", &a[i]);
    sum += a[i];
  }
  maxi = sum;
  for (int i = 0; i < k; ++i) {
    scanf("%d", &b[i]);
    if (b[i] >= 1) {
      maxi = min(maxi, a[i] / b[i]);
    }
  }
  int ans = 1;
  for (int i = maxi; i >= 1; --i) {
    if (sum % i) continue;
    ans = i;
    break;
  }
  vector<int> req;
  int cnt = sum / ans;
  vector<int> others;
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < b[i]; ++j) {
      req.push_back(i);
    }
    a[i] -= b[i] * ans;
    for (int j = 0; j < a[i]; ++j) {
      others.push_back(i);
    }
  }
  vector<vector<int>> elems(ans);
  for (int i = 0, j = 0; i < ans; ++i) {
    elems[i] = req;
    while ((int)elems[i].size() < cnt) {
      elems[i].push_back(others[j++]);
    }
  }
  printf("%d %d\n", ans, cnt);
  for (auto & v : elems) {
    for (int i = 0; i < cnt; ++i) {
      printf("%d%c", v[i] + 1, i + 1 == cnt ? '\n' : ' ');
    }
  }
  return 0;
}
