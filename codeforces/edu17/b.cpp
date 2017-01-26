#include <bits/stdc++.h>

using namespace std;

int a, b, c, m;
char s[100];

int main() {
  scanf("%d %d %d %d", &a, &b, &c, &m);
  vector< int > u[2];
  while (m--) {
    int v;
    scanf("%d %s", &v, s);
    if (s[0] == 'U')
      u[0].push_back(v);
    else
      u[1].push_back(v);
  }
  sort(u[0].begin(), u[0].end());
  sort(u[1].begin(), u[1].end());
  int id[2];
  id[0] = id[1] = 0;
  int ans = 0;
  long long sum = 0;
  while (a-- && id[0] < u[0].size()) {
    ans++;
    sum += u[0][id[0]++];
  }
  while (b-- && id[1] < u[1].size()) {
    ans++;
    sum += u[1][id[1]++];
  }
  vector<int > all;
  for (int i = 0; i < 2; i++)
    while (id[i] < u[i].size())
      all.push_back(u[i][id[i]++]);
  sort(all.begin(), all.end());
  int now = 0;
  while (c-- && now < all.size()) {
    ans++;
    sum += all[now++];
  }
  cout << ans << " " << sum << endl;
  return 0;
}