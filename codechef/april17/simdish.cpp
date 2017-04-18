#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    set< string > a;
    string s;
    for (int i = 0; i < 4; i++) {
      cin >> s;
      a.insert(s);
    }
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
      cin >> s;
      cnt += a.count(s);
    }
    puts(cnt >= 2 ? "similar" : "dissimilar");
  }
  return 0;
}