#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;
char s[N];

int cnt[256];
int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n, k;
    scanf("%s%d", s, &k);
    n = strlen(s);
    memset(cnt, 0, sizeof cnt);
    for(int i = 0; i<=n-k; i++)
      cnt[s[i]]++;
    char now = 'a';
    for(int i = 0; i<=n-k; i++) {
      while(cnt[now] == 0) now++;
      if(s[i] == now) {
        printf("%c", s[i]);
        k--;
        if(k) {
          cnt[s[n-k]]++;
          now = min(now, s[n-k]);
        }
        else break;
      }
      cnt[s[i]]--;
    }
    while(k) {
      printf("%c", s[n-k]);
      k--;
    }
    printf("\n");
  }

  return 0;
}