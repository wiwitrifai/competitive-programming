#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

int ans[N];
int val[50];
char s[N];

int main() {
  int cnt = 0, n;
  scanf("%d", &n);
  cnt = n;
  int now = 0;
  while(cnt) {
    int cur = 0;
    int bef = now;
    while(cur < 3) {
      if(ans[now] == 0) {
        val[cur++] = now;
      }
      now++;
      now %= n;
      if(now == bef)
        break;
    }
    if(cur == 1) {
      int neg = -1;
      for(int i = 0; i<n; i++) if(ans[i] < 0) {
        neg = i;
        break;
      }
      if(neg > -1) {
        printf("2\n%d %d\n", neg+1, val[0]+1);
        fflush(stdout);
        scanf("%s", s);
        if(s[1] == 'S')
          ans[val[0]] = 1;
        else
          ans[val[0]] = -1;
      }
      else {
        neg = (val[0] + 1) % n;
        printf("2\n%d %d\n", val[0]+1, neg+1);
        fflush(stdout);
        scanf("%s", s);
        if(s[0] == 'S')
          ans[val[0]] = 1;
        else
          ans[val[0]] = -1;
      }
      break;
    }
    printf("%d\n", cur);
    for(int i = 0; i<cur; i++)
      printf("%d ", val[i]+1);
    printf("\n");
    fflush(stdout);
    scanf("%s", s);
    int cc = 0;
    for(int i = 0; i<cur; i++) {
      if(s[i] == 'S') {
        ans[val[i]] = 1;
        cnt--;
      }
      else
        cc++;
    }
    if(cc > 1 || (cc == cur)) {
      for(int i = 0; i<cur; i++) if(s[i] == 'C') {
        cnt--;
        ans[val[i]] = -1;
      }
    }
  }
  printf("-1\n");
  for(int i = 0; i<n; i++)
    printf("%c", ans[i] > 0 ? 'J' : 'R');
  printf("\n");
  fflush(stdout);
  return 0;
}