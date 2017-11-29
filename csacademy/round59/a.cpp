#include <bits/stdc++.h>

using namespace std;

int cnt[256];

int main() {
  string s;
  int n;
  cin >> n;
  cin >> s;
  for (int i = 0; i < s.size(); i++)
    cnt[s[i]]++;
  for (int i = 0; i < s.size(); i++) {
    if (cnt[s[i]] == 1) {
      cout << s[i] << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}