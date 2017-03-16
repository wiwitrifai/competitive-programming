#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    set< string > st;
    int bantu = 0;
    while (n--) {
      int k;
      string s;
      cin >> s >> k;
      if (s[0] == 'd')
        bantu = max(bantu, k);
      while (k--) {
        cin >> s;
        st.insert(s);
      }
    }
    printf("%d\n", st.size() + (st.size() == bantu));
  }

  return 0;
}