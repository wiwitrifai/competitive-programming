#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n, 0);
  vector<int> b(n, 0);
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  while (m--) {
    char op;
    int l, r, v;
    cin >> op;
    if (op == 'F') {
      cin >> l >> r >> v;
      --l;
      for (int i = l; i < r; ++i) {
        if (b[i]) continue;
        a[i] = v;
      }
    } else if (op == 'I') {
      cin >> v;
      a.push_back(v);
      b.push_back(0);
    } else if (op == 'L') {
      cin >> l >> r;
      --l;
      for (int i = l; i < r; ++i)
        b[i] = 1;
    } else if (op == 'C') {
      cin >> l >> r;
      --l;
      for (int i = l; i < r; ++i)
        b[i] = 0;
    } else {
      cin >> l >> r;
      --l;
      long long sum = 0;
      for (int i = l; i < r; ++i)
        sum += a[i];
      cout << sum << '\n';
    }
    cerr << "                   " << op << endl;
    for (int j = 0; j < (int)a.size(); ++j) {
      cerr << a[j] << " ";
    }
    cerr << endl;
    for (int j = 0; j < (int)a.size(); ++j) {
      cerr << b[j] << " ";
    }
    cerr << endl;
  }
  return 0;
}
