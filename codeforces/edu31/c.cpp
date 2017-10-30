#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int p[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", p+i);
  }
  vector<int> sz;
  for (int i = 1; i <= n; i++) if (p[i] != -1) {
    int now = i;
    int cnt = 0;
    while(p[now] != -1) {
      cnt++;
      int x = p[now];
      p[now] = -1;
      now = x;
    }
    sz.push_back(cnt);
  }
  sort(sz.begin(), sz.end());
  long long ans = 0;
  for (int s : sz)
    ans += 1LL * s * s;
  if (sz.size() >= 2)
    ans += 2LL * sz.back() * sz[(int)sz.size()-2];
  cout << ans << endl;
  return 0;
}