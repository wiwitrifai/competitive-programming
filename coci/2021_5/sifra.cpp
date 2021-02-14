#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  cin >> s;
  for (int i = 0; i < (int)s.size(); ++i) {
    if (s[i] < '0' || s[i] > '9')
      s[i] = ' ';
  }
  stringstream ss(s);
  set<int> st;
  int x;
  while (ss >> x) {
    st.insert(x);
  }
  cout << st.size() << '\n';
  return 0;
}
