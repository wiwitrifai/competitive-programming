#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;
int n, k;
char s[N];

int main() {
  scanf("%d%d", &n, &k);
  scanf("%s", s);
  int l = 0, cnt = 0, ans = 0;
  for(int i = 0; i<n; i++) {
    if(s[i] == 'a')
      cnt++;
    while(cnt > k) {
      if(s[l] == 'a')
        cnt--;
      l++;
    }
    ans = max(ans, i-l+1);
  }
  cnt = l = 0;
  for(int i = 0; i<n; i++) {
    if(s[i] == 'b')
      cnt++;
    while(cnt > k) {
      if(s[l] == 'b')
        cnt--;
      l++;
    }
    ans = max(ans, i-l+1);
  }
  cout << ans << endl;
  return 0;
}