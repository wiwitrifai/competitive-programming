#include <bits/stdc++.h>

using namespace std;

char s[5000];
int main() {
  scanf("%d", s);
  int n = strlen(s);
  int indent = 0;
  int now = 0;
  while(now < n) {
    for(int i = 0; i<indent; i++)
      printf("  ");
    switch(s[now]) {
      case '{':   
        printf("{"); indent++;
        now++;
        break;
      case '}':
        printf("}"); indent--;
        if(s[++now] == ',')
          printf(",");
        now++;
        break;
      default:
        while(s[now] <= 'z' && s[now] >= 'a') {
          printf("%c", s[now]);
          now++;
        }
        if(s[now == ',']) {
          printf(",");
          now++;
        }
    }
    printf("\n");
  }
  return 0;
}