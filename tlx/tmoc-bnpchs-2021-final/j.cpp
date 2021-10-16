#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  int cnt = 1;
  int n = s.size();
  for (int i = 1; i < n; ++i) {
    cnt += s[i] != s[i-1];
  }
  vector<int> grund(cnt+1, 0);
  for (int i = 1; i <= cnt; ++i) {
    set<int> st;
    st.insert(grund[i-1]);
    if (i > 2) {
      st.insert(grund[i-2]);
    }
    for (int x : st) {
      grund[i] = grund[i] == x;
    }
  }
  cout << (grund[cnt] ? "Filco" : "Riberto") << endl;
  return 0;
}
