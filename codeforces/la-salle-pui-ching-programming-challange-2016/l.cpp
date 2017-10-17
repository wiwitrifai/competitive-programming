#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;

int a[N];

map<int, int> cnt;
map<int, pair<double, double> > prob;

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
    cnt[a[i]]++;
  }
  int cur = 0;
  for (auto it : cnt) {
    cur += it.second;
    prob[it.first] = make_pair((double)(n - cur)/n, (double)(it.second)/n);
  }
  for (int i = 0; i < n; i++) {
    auto it = prob[a[i]];
    printf("%.7lf %.7lf %.7lf\n", it.first, it.second, 1 - it.first - it.second);
  }
  return 0;
}