/**
 * Coded by Luqman
 */

#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

bool cmp(pair<string, int> a, pair<string, int> b) {
  for (int i = 0; i < (int) a.first.size(); i++) {
    if (a.first[i] != b.first[i]) {
      if (i % 2 == 0) {
        return a.first[i] < b.first[i];
      } else {
        return a.first[i] > b.first[i];
      }
    }
  }
  return a < b;
}

char s[N];

int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<string, int>> a;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    a.emplace_back(s, i);
  }
  sort(a.begin(), a.end(), cmp);
  for (int i = 0; i < n; i++) {
    printf("%d%c", a[i].second + 1, i == n - 1? '\n' : ' ');
  }

  return 0;
}
