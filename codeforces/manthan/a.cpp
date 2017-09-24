#include <bits/stdc++.h>

using namespace std;

set<string > st;

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    if (st.count(s))
      puts("YES");
    else
      puts("NO");
    st.insert(s);
  }
  return 0;
}