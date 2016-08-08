#include <bits/stdc++.h>

using namespace std;

int t;
char s[10000];
int to[256];

int main() {
  for(int i = 0; i<10; i++)
    to['0' + i] = i;
  for(int i = 0; i<26; i++)
    to['a' + i] = i + 10;
  for(int i = 0; i<26; i++)
    to['A' + i] = i + 36;
  scanf("%d", &t);
  while(t--) {
    scanf("%s", s);
    int n = strlen(s);
    int mi = 0;
    for(int i = 0; i < n; i++)
      mi = max(mi, to[s[i]]);
    printf("%d 62\n", mi+1);
  }
  
  return 0;
}