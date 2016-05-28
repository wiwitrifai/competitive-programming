#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e5 + 5;
 
char s[N];
int cnt[26];
 
int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    memset(cnt, 0, sizeof(cnt));
    
    int k;
    scanf("%s %d", s, &k);
    int n = strlen(s);
    for(int i = 0; i < n; i++) {
      cnt[s[i] - 'a']++;
    }
    sort(cnt, cnt+26);
    int ans = 1e9, sum = 0;
    for(int i = 0; i < 26; i++) if(cnt[i]) {
      int now = sum;
      for(int j = i; j<26; j++)
        now += max(0, cnt[j]-cnt[i]-k);
      ans = min(ans, now);
      sum += cnt[i];
    }
    ans = min(ans, sum);
    printf("%d\n", ans);
  }
  return 0;
}