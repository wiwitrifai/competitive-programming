#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
      scanf("%d", &v[i]);
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    bool ans = false;
    while (v.size() > 1 && v.back() < 2048) {
      int sz = v.size();
      if (v[sz-1] == v[sz-2]) {
        v[sz-2] += v[sz-1];
      }
      v.pop_back();
      sort(v.begin(), v.end());
      reverse(v.begin(), v.end());
    }
    if (!v.empty() && v.back() == 2048)
      ans = true;
    puts(ans ? "YES" : "NO");
  }
  return 0;
}
