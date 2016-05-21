#include <bits/stdc++.h>

using namespace std;

int cnt[30];
int main() {
  int n = 0;
  for(int i = 0; i<26; i++) {
    scanf("%d", cnt+i);
    n += cnt[i];
  }
  int a, b;
  a = -1;
  for(int i = 0; i < 26; i++) {
    if(cnt[i] > 0)
      if(a == -1 || cnt[i] < cnt[a])
        a = i;
  }
  printf("%c", a+'a');
  cnt[a]--;
  n--;
  if(cnt[a] == n) {
    while(n--) {
      printf("%c", a+'a');
    }
    printf("\n");
    return 0;
  }
  if(n == 0) {
    printf("\n");
    return 0;
  }
  b = a;
  int res = n-cnt[a];
  for(int i = 0; i<a; i++) {
    if(cnt[i] > 0 && n - cnt[a] - cnt[i] >= cnt[a]-1) {
      b = i;
      res -= cnt[b];
      break;
    }
  }
  printf("%c", b+'a');
  cnt[b]--;
  n--;
  int last = b;
  while(n--) {
    for(int j = 0; j<26; j++) if(cnt[j]) {
      if(last == a) {
        if(j == a || j == b)
          continue;
        printf("%c", j + 'a');
        cnt[j]--;
        res--;
        last = j;
        break;
      }
      else {
        if((j == a) || (j == b) || res >= cnt[a]) {
          // cout << cnt[j] << endl;
          printf("%c", j+'a');
          cnt[j]--;
          last = j;
          res -= (j != a) && (j != b);
          break;
        }
      }
    }    
  }
  printf("\n");

  return 0;
}