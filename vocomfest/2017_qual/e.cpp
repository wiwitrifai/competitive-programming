#include <bits/stdc++.h>

using namespace std;

const int N = 111;

pair< int, int > pos[N];
long long dist(pair< int, int > a, pair< int, int > b) {
  long long dx = a.first - b.first, dy = a.second - b.second;
  return abs(dx) + abs(dy);
}
string name[N];

int main() {
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
      cin >> name[i] >> pos[i].first >> pos[i].second;
    }   
    printf("Case #%d:\n", tc);
    for (int i = 0; i < m; i++) {
      int a, b, c, d;
      cin >> a >> b >> c >> d;
      pair< int, int > from(a, b), to(c, d);
      long long now = 1e17;
      int sel = 0;
      for (int j = 0; j < n; j++) {
        long long cur = dist(pos[j], from);
        if (cur == now && name[j] < name[sel])
          sel = j;
        else if (cur < now) {
          now = cur;
          sel = j;
        }
      }
      cout << name[sel] << endl;
      pos[sel] = to;
    }
  }
  return 0;
}