#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    set<int> prince;
    vector<int> princess;
    for (int i = 1; i <= n; ++i) {
      prince.insert(i);
    }
    for (int i = 1; i <= n; ++i) {
      int k;
      scanf("%d", &k);
      bool found = 0;
      while (k--) {
        int x;
        scanf("%d", &x);
        if (!found && prince.count(x)) {
          found = 1;
          prince.erase(x);
        }
      }
      if (!found)
        princess.push_back(i);
    }
    if (princess.empty()) {
      puts("OPTIMAL");
      continue;
    }
    puts("IMPROVE");
    auto it = prince.begin();
    printf("%d %d\n", princess[0], *it);
  }
  return 0;
}
