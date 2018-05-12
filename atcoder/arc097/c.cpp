#include <bits/stdc++.h>

using namespace std;

string s;
int mulai[5050];

int main() {
  int k;
  cin >> s >> k;
  int n = s.size();
  set<string> st;
  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j <= n && j <= i+10; ++j) {
      string now = s.substr(i, j-i);
      st.insert(now);
      while (st.size() > k) {
        auto it = --st.end();
        st.erase(it);
      }
    }
  }
  cout << *(--st.end()) << endl;
  return 0;
}