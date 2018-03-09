#include <bits/stdc++.h>

using namespace std;

int ans[55], nans, tmp[55];

void unique(vector<int> & a) {
  a.erase(unique(a.begin(), a.end()), a.end());
}

void solve(const vector<int> &a, int t, int num) {
  if (num >= nans) return;
  if (a.empty() || (a.size() == 1 && a.back() == 0)) {
    nans = num;
    for (int i = 0; i < num; ++i)
      ans[i] = tmp[i];
  }
  if (t > 18) return;
  vector<int> odd, even;
  for (int x : a) {
    if (abs(x) & 1)
      odd.push_back((x-1)/2);
    else
      even.push_back(x/2);
  }
  if (odd.empty()) {
    solve(even, t+1, num);
    return;
  }
  vector<int> cur;
  cur.resize(odd.size() + even.size());
  merge(odd.begin(), odd.end(), even.begin(), even.end(), cur.begin());
  unique(cur);
  tmp[num] = 1 << t;
  solve(cur, t+1, num+1);

  for (int & x : odd) ++x;
  cur.resize(odd.size() + even.size());
  merge(odd.begin(), odd.end(), even.begin(), even.end(), cur.begin());
  unique(cur);
  tmp[num] = -(1 << t);
  solve(cur, t+1, num+1);
}


int main() {
  vector<int> a;
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    a.push_back(x);
  }
  sort(a.begin(), a.end());
  unique(a);
  nans = 0;
  for (int i = 0; i < 18; ++i) {
    ans[nans++] = 1 << i;
    ans[nans++] = -(1 << i);
  }
  solve(a, 0, 0);
  printf("%d\n", nans);
  for (int i = 0; i < nans; ++i)
    printf("%d ", ans[i]);
  printf("\n");
  return 0;
}