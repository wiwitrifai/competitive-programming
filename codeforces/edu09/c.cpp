#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5;
int n;
string s[N];

bool cmp(string a, string b) {
  return a + b < b + a;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i<n; i++) {
    cin >> s[i];
  }
  sort(s, s+n, cmp);
  for(int i = 0; i<n; i++)
    cout << s[i];
  cout << endl;
  return 0;
}