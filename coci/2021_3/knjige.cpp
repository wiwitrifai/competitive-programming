#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> d(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &d[i]);
  }
  vector<int> s = d;
  sort(s.begin(), s.end());
  vector<tuple<int, int, int>> moves;
  for (int i = n-1; i >= 0; --i) {
    if (d[i] != s[i]) {
      int found = -1;
      int moved = 0;
      for (int j = 0; j <= i; ++j) {
        if (d[j] != s[i] || found != -1) {
          moves.emplace_back(0, 1, 0);
          moves.emplace_back(1, 1, 1);
          ++moved;
          if (found != -1)
            swap(d[j-1], d[j]);
        } else {
          found = j;
          moves.emplace_back(0, 0, 0);
        }
      }
      assert(s[i] == d[i]);
      moves.emplace_back(1, 0, 0);
      for (int j = 0; j < moved; ++j) {
        moves.emplace_back(0, 1, 1);
        moves.emplace_back(1, 1, 0);
      }
    }
  }
  printf("%d\n", (int)moves.size());
  for (auto & it : moves) {
    int op, hand, shelf;
    tie(op, hand, shelf) = it;
    printf("%s %c %c\n", op ? "STAVI" : "UZMI", hand ? 'D' : 'L', shelf ? 'D' : 'L');
  }
  return 0;
}
