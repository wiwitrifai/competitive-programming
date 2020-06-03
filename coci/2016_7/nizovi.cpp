#include <bits/stdc++.h>

using namespace std;

char s[5000];
int main() {
  scanf("%s", s);
  int n = strlen(s);
  int indent = 0;
  int now = 0;
  while(now < n) {
    switch(s[now]) {
      case '{':
        for(int i = 0; i<indent; i++)
          printf("  ");
        printf("{"); indent++;
        now++;
        break;
      case '}':
        indent--;
        for(int i = 0; i<indent; i++)
          printf("  ");
        printf("}");
        if(s[now+1] == ',') {
          printf(",");
          now++;
        }
        now++;
        break;
      default:
        for(int i = 0; i<indent; i++)
          printf("  ");
        while(s[now] <= 'z' && s[now] >= 'a') {
          printf("%c", s[now]);
          now++;
        }
        if(s[now] == ',') {
          printf(",");
          now++;
        }
    }
    printf("\n");
  }
  return 0;
}