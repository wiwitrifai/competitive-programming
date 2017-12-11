#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  set<int> st;
  a *= 10;
  for (int i = 1; ; ++i) {
    if (st.count(a)) break;
    st.insert(a);
    int d = 0;
    d = a/b;
    a -= d * b;
    a *= 10;
    // cerr << d << " ";
    if (d == c) {
      printf("%d\n", i);
      return 0;
    }
  }
  puts("-1");
  return 0;
}