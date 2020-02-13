#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    string a, b, c;
    cin >> a >> b >> c;
    bool ok = 1;
    for (int i = 0; i < a.size(); ++i) {
      ok &= c[i] == a[i] || c[i] == b[i];
    }
    puts(ok ? "YES" : "NO");
  }
  return 0;
}
