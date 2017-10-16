#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

pair<int, string> s[N];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string str;
    int k;
    cin >> str >> k;
    s[i] = {k, str};
  }
  sort(s, s + n);
  for (int i = 0; i < n; i++) {
    int j = i;
    while (j + 1 < n && s[j + 1].first == s[j].first) j++;
    for (int k = i; k <= j; k++) {
      if (k > i) printf(" ");
      printf("%s", s[k].second.c_str());
    }
    printf(" %d %d\n", i + 1, j + 1);
    i = j;
  }
  return 0;
}
