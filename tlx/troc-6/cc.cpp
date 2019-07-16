#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char s[N];

bool used[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  scanf("%s", s+1);
  s[0] = '0';
  s[n+1] = '0';
  vector<pair<int, int>> ans;
  vector<int> add, awal, sisa;
  for (int i = 1; i <= n; ++i) {
    if (used[i-1] || used[i+1]) continue;
    if (s[i] == '0') continue;
    awal.push_back(i);
    used[i] = 1;
  }
  for (int i = 1; i <= n; ++i) {
    if (used[i-1] || used[i+1] || used[i]) continue;
    assert(s[i] == '0');
    add.push_back(i);
    used[i] = 1;
    ans.emplace_back(1, i);
  }
  for (int x : awal)
    ans.emplace_back(1, x);
  for (int i = 1; i <= n; ++i) {
    if (used[i] || s[i] == '0') continue;
    ans.emplace_back(1, i);
  }
  for (int i = 0; i < add.size(); ++i)
    ans.emplace_back(2, add[i]);
  printf("%d\n", (int)ans.size());
  for (auto it : ans) {
    if (it.first == 1)
      printf("1 %d\n", it.second);
    else
      printf("2\n");
  }
  return 0;
}
