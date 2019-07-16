#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

char s[N], t[N];
int b[N];
int zero = 0, one = 0;

void print(char c) {
  if (c == '1') {
    if (one > 0) {
      printf("1");
      --one;
    }
    else {
      printf("0");
      --zero;
    }
  }
  else {
    if (zero > 0) {
      printf("0");
      --zero;
    }
    else {
      printf("1");
      --one;
    }
  }
}

int main() {
  scanf("%s", s);
  scanf("%s", t);
  one = zero = 0;
  int n = strlen(s), m = strlen(t);
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1')
      ++one;
    else
      ++zero;
  }
  memset(b, 0, sizeof b);
  for(int i = 1; i < m; i++) {
    int j = b[i - 1];
    while(j > 0 && t[i] != t[j]) j = b[j - 1];
    if(t[i] == t[j]) b[i] = j + 1;
  }
  int same = b[m-1];
  for (int i = 0; i < min(m, n); ++i) { 
    print(t[i]);
  }
  // cerr << endl;
  // cerr << t << endl;
  for (int i = m; i < n;) {
    int len = min(m - same, n-i);
    for (int j = 0; j < len; ++j) {
      print(t[same+j]);
    }
    i += len;
  }
  printf("\n");
  return 0;
}