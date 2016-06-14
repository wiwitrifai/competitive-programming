#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;
int ans[N];
char s[N];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  int cnt = 0;
  for(int i = 0; i<n; i++)
    if(s[i] == 'A') {
      ans[i]++;
      ans[0]--;
      cnt++;
    }
  for(int i = 0; i<n; i++) {
    if(s[i] == 'A') {
      ans[i+1] -= cnt;
      ans[i] += cnt;
      cnt--;
    }
  }
  for(int i = n; i>0; i--) {
    ans[i-1] += ans[i];
  }
  for(int i = 1; i<n; i++)
    printf("%d\n", ans[i]);
  return 0;
}