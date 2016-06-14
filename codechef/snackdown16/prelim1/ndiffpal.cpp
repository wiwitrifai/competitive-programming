#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d", &n);
    int cur = n;
    char now = 'a';
    while(n) {
      int val = cur * (cur + 1)/2;
      if(val <= n) {
        n -= val;
        for(int i = 0; i<cur; i++)
          printf("%c", now);
        now++;
        if(now > 'z')
          now = 'a';
      }
      else
        cur--;
    }
    printf("\n");
  }

  return 0;
}