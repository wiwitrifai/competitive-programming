#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, inf = 1e9 + 7;

pair< pair<int, int >, pair<int, int > > sith[N];
bitset< N >  loser;

int main() {
  loser.set();
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    sith[i] = {{a, b}, {c, i+1}};
  }
  sort(sith, sith+n);
  int j = 0;
  int b = inf, c = inf;
  for (int i = 0; i < n; i++) {
    while (j < i && sith[j].first.first < sith[i].first.first) {
      b = min(b, sith[j].first.second);
      c = min(c, sith[j].second.first);
      j++;
    }
    if (b < sith[i].first.second || c < sith[i].second.first)
      loser[sith[i].second.second] = 0;
  }
  for (int i = 0; i < n; i++) {
    swap(sith[i].first.first, sith[i].first.second);
  }

  sort(sith, sith+n);
  j = 0;
  b = inf, c = inf;
  for (int i = 0; i < n; i++) {
    while (j < i && sith[j].first.first < sith[i].first.first) {
      b = min(b, sith[j].first.second);
      c = min(c, sith[j].second.first);
      j++;
    }
    if (b < sith[i].first.second || c < sith[i].second.first)
      loser[sith[i].second.second] = 0;
  }
  for (int i = 0; i < n; i++) {
    swap(sith[i].first.first, sith[i].second.first);
  }
  sort(sith, sith+n);
  j = 0;
  b = inf, c = inf;
  for (int i = 0; i < n; i++) {
    while (j < i && sith[j].first.first < sith[i].first.first) {
      b = min(b, sith[j].first.second);
      c = min(c, sith[j].second.first);
      j++;
    }
    if (b < sith[i].first.second || c < sith[i].second.first)
      loser[sith[i].second.second] = 0;
  }
  vector< int > ans;
  for (int i = 1; i <= n; i++) if (loser[i])
    ans.push_back(i);
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); i++) {
    printf("%d ", ans[i]);
  }
  if (ans.size())
    printf("\n");
  return 0;
}