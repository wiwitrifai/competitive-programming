#include <bits/stdc++.h>

using namespace std;

const int N = 505;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++i) {
      scanf("%d", &b[i]);
    }
    auto transform = [](vector<int> &v) {
      vector<pair<int, int>> val;
      int i = 0, j = (int)v.size()-1;
      while (i < j) {
        int x = v[i++], y = v[j--];
        if (x > y)
          swap(x, y);
        val.emplace_back(x, y);
      }
      if (i == j)
        val.emplace_back(-1, v[i]);
      sort(val.begin(), val.end());
      return val;
    };
    puts((transform(a) == transform(b)) ? "Yes" : "No");
  }
  return 0;
}
