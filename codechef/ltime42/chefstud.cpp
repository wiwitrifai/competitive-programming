#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 7;

char s[N];

int main(){
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", s);
    int n = strlen(s);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      cnt += s[i] == '<' && s[i+1] == '>';
    }
    printf("%d\n", cnt);
  }
  return 0;
}