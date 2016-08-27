#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 5;

char s[9][N];

int main() {
  for(int i = 0; i<9; i++)
    scanf("%s", s[i]);
  int len = strlen(s[0]);
  int now = 2;
  while(now < len) {
    if(s[1][now] == '1')
      printf(" ");
    else if(s[4][now] == '1')
      printf("C");
    else if(s[7][now] == '1')
      printf("A");
    else
      printf("B");
    now += 5;
  }
  printf("\n");
  return 0;
}