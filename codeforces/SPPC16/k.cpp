#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int cnt[26][2];
char s[N];

string str[2] = {"kangaroo", "kiwibird"};

int main() {
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < str[i].size(); j++) {
     cnt[str[i][j] - 'a'][i]++;
    }
  }
  
  scanf("%s", s);
  int n = strlen(s);
  int a = 0, b = 0;
  for (int i = 0; i < n; i++) {
    int c = ('A' <= s[i] && s[i] <= 'Z'? s[i] - 'A' : s[i] - 'a');
    a += cnt[c][0]++;
    b += cnt[c][1]++;
  }
  if (a > b) {
    puts("Kangaroos");
  } else if (a < b) {
    puts("Kiwis");
  } else {
    puts("Feud continues");
  }
  return 0;
}