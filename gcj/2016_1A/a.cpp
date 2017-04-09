/*
  iafir
  GCJ2016 Round 1A Problem A
  -Accepted-
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 1024;
char s[N];
bool ok[N];

int main() {
  int tt;
  scanf("%d", &tt);
  for(int tc = 1; tc <= tt; tc++) {
    scanf("%s", s);
    printf("Case #%d: ", tc);
    int n = strlen(s);
    char now = '\0';
    for(int i = 0; i<n; i++) {
      now = max(now, s[i]);
      ok[i] = (now == s[i]);
    }
    for(int i = n-1; i>=0; i--) if(ok[i])
      printf("%c", s[i]);
    for(int i = 0; i<n; i++) if(!ok[i])
      printf("%c", s[i]);
    printf("\n");
    cerr << "Case #"<<tc << " Done" << endl;
  }
  return 0;
}