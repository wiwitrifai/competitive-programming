#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  string s;
  cin >> s;
  sort(s.begin(), s.end());
  printf("%c\n", s[k-1]);
  return 0;
}
