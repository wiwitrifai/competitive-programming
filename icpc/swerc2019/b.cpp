#include <bits/stdc++.h>

using namespace std;

char buffer[500];

int main() {
  int n;
  scanf("%d", &n);
  map<string, int> st;
  for (int i = 0; i < n; ++i) {
    scanf("%s", buffer);
    ++st[buffer];
  }
  for (auto it : st) {
    if (it.second * 2 > n) {
      cout << it.first << endl;
      return 0;
    }
  }
  puts("NONE");
  return 0;
}
