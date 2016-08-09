#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

char s[N];

int main() {
  scanf("%s", s);
  int nzero = -1;
  int dot = -1;
  int n = strlen(s);
  for(int i = 0; i<n; i++) {
    if(s[i] != '0' && s[i] != '.' && nzero == -1)
      nzero = i;
    if(s[i] == '.')
      dot = i;
  }
  if(dot == -1)
    dot = n;
  int nlast = -1;
  for(int i = n-1; i>=0; i--) if(s[i] != '0' && s[i] != '.' && nlast == -1)
    nlast = i;
  int now = nzero;
  if(now == -1) {
    printf("0");
  }
  else {
    printf("%c", s[now]);
    now++;
    if(s[now] == '.')
      now++;
  }
  if(nlast != -1 && now <= nlast) {
    printf(".");
    while(now <= nlast) {
      if(s[now] != '.')
        printf("%c", s[now]);
      now++;
    }
  }
  int b = dot == -1 ? 0 : dot-nzero-(dot > nzero);
  if(b)
    printf("E%d\n", b);
  else
    printf("\n");
  return 0;
}