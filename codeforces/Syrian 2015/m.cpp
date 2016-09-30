#include <bits/stdc++.h>

using namespace std;

const int N = 105;

vector< string > vol[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    vector< pair<int, int> > event;
    for (int i = 1; i <= n; i++) {
      int s, e, m;
      scanf("%*s %d %d %d", &s, &e, &m);
      event.push_back({s, i});
      event.push_back({e+1, -i});
      vol[i].clear();
      for (int j = 0; j < m; j++) {
        string str;
        cin >> str;
        vol[i].push_back(str);
      }
    }
    set< string > ans;
    set< string > active;
    sort(event.begin(), event.end());
    for (auto e : event) {
      int now = e.second;
      if (now < 0) {
        now = -now;
        for (string mem : vol[now])
          active.erase(mem);
      }
      else {
        for (string mem : vol[now]) {
          if (active.count(mem)) {
            ans.insert(mem);
          }
          else {
            active.insert(mem);
          }
        }
      }
    }
    printf("%d\n", ans.size());
    for (string name : ans) {
      printf("%s\n", name.c_str());
    }
  }

  return 0;
}