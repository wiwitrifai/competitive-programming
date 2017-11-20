#include <bits/stdc++.h>

using namespace std;

const int N = 10;

int a[N];
int tmp[N];
vector<pair<int, int>> all;

int main() {
  int n = 4;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      all.emplace_back(i, j);
    }
  }
  int t;
  scanf("%d", &t);
  int til = 729;
  for (int tt = 1; tt <= t; tt++) {
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
    }
    int ada = 0;
    for (int h = 0; h < til; h++) {
      memset(tmp, 0, sizeof(tmp));
      int val = h;
      for (auto it : all) {
        int c = val % 3;
        val /= 3;
        if (c == 0) {
          tmp[it.first] += 3;
        } else if (c == 1) {
          tmp[it.first]++;
          tmp[it.second]++;
        } else {
          tmp[it.second] += 3;
        }
      }
      bool same = 1;
      for (int i = 0; i < n; i++) if (a[i] != tmp[i]) same = 0;
      if (same) ada++;
    }
    printf("Case #%d: ", tt);
    if (ada == 1) {
      puts("Yes");
    } else if (ada > 1) {
      puts("No");
    } else {
      puts("Wrong Scoreboard");
    }
  }

  return 0;
}