#include <bits/stdc++.h>

using namespace std;

char s[10006];
int a, b;
int main() {
  scanf("%d.%[0-9]e%d", &a, s, &b);
  printf("%d", a);
  int now = 0;
  int n = strlen(s);
  for(int i = 0; i<b; i++)
    s[n+i] = '0';
  while(b--) {
    printf("%c", s[now++]);
  }
  bool ok = false;
  for(int i = now; i<n; i++)
    ok |= (s[i] != '0');
  if(ok) {
    s[n] = '\0';
    printf(".%s", s+now);
  }
  printf("\n");
  return 0;
}