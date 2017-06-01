#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n, k;
char s[N];

int main() {
  scanf("%d%d", &n, &k);
  scanf("%s", s);
  int diff = 0;
  for(int i = 0; i+i<n; i++) {
    diff += s[i] != s[n-i-1];
  }
  if(diff > k) {
    puts("-1");
    return 0;
  }
  int now = 0;
  while(k >= diff && now+now < n) {
    if(s[now] != s[n-now-1]) {
      diff--;
      if(k - diff > 1 && max(s[now], s[n-now-1]) == '9') {
        s[now] = s[n-now-1] = '9';
        k-=2;
      }
      else {
        s[now] = s[n-now-1] = max(s[now], s[n-now-1]);
        k--;
      }
    }
    else {
      if(k-diff > 1 && s[now] != '9') {
        k-=2;
        s[now] = s[n-now-1] = '9';
      }
    }
  }
  printf("%s\n", s);
  return 0;
}