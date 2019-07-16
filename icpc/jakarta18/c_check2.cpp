#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

char s[N];

int main() {
  int n;
  scanf("%s %d", s, &n);
  int len = strlen(s);
  bool ok = 1;
  for (int i = 0; i + n <= len; ++i) {
    for (int j = i+1; j + n <= len; ++j){
      bool found = 0;
      for (int k = 0; k < n; ++k) {
        if (s[i+k] != s[j+k]) {
          found = 1;
          break;
        }
      }
      if (!found) {
        cerr << " fail " << endl;
        cerr << i << " " << j << endl;
        return 0;
      }
    }
  }
  cerr << " ok " << endl;
  return 0;
}