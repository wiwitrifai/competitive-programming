#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    assert(x == 0 || x == 1);
  }
  for (int i = 2; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    assert(x < i);
  }
  for (int i = 0; i < q; ++i) {
    string s;
    int x, y, z;
    cin >> s;
    assert(s.size() == 1);
    assert(s[0] == 'C' || s[0] == 'T' || s[0] == 'K');
    if (s[0] == 'T')
      cin >> x;
    else if (s[0] == 'C') {
      cin >> x >> y;
      assert(y < x);
    }
    else
      cin >> x >> y >> z;
  }

  return 0;
}