#include <bits/stdc++.h>

using namespace std;

pair<int, int > p[4];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    for (int i = 0; i < 4; i++) {
      scanf("%d %d", &p[i].first, &p[i].second);
    }
    map<int, int> mp;
    for (int i = 0; i < 4; i++) {
      for (int j = i+1; j < 4; j++) {
        int dx = p[i].first - p[j].first, dy = p[i].second - p[j].second;
        int dd = dx * dx + dy * dy;
        mp[dd]++;
      }
    }
    if (mp.size() != 2) {
      puts("0");
    }
    else {
      auto it = mp.begin();
      auto nx = it;
      nx++;
      printf("%d\n", (it->second == 4 && nx->second == 2 && it->first * 2 == nx->first));
    }
  }

  return 0;
}