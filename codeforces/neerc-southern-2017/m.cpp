#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, x;
  scanf("%d", &n);
  set<int> st;
  for (int i = 0; i < n; i++) {
    int y;
    scanf("%d", &y);
    if (i)
      st.insert(y-x);
    x = y;
  }
  if (st.size() == 1) {
    printf("%d\n", x + *st.begin());
  }
  else
    printf("%d\n", x);
  return 0;
}