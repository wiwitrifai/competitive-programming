#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int cnt[26];

char s[N];
int main() {
  scanf("%s", s);
  memset(cnt, 0, sizeof cnt);
  int n = strlen(s);
  for(int i = 0; i<n; i++)
    cnt[s[i]-'a']++;
  int l = 0, r = 25;
  char mid = '\0';
  while(l < r) {
    while((cnt[l] & 1) == 0 && l < r) l++;
    while((cnt[r] & 1) == 0 && l < r) r--;
    if(l < r) {
      cnt[l]++;
      cnt[r]--;
    }
    else {
      if(cnt[l] & 1)
        mid = l+'a';
    }
  }
  for(int i = 0; i<26; i++) {
    cnt[i]/=2;
    for(int j = 0; j<cnt[i]; j++)
      printf("%c", 'a' + i);
  }
  if(mid)
    printf("%c", mid);
  for(int i = 25; i>=0; i--) {
    for(int j = 0; j<cnt[i]; j++)
      printf("%c", 'a' + i);
  }
  printf("\n");
  return 0;
}