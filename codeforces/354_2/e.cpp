#include <bits/stdc++.h>

using namespace std;

int n, k;

double dmod[] = {1e9 + 9, 1e9 + 87, 1e9 + 4207, 2e9 + 89, 2e9 + 143, 2e9 + 11, 2e9 + 1851, 2e9 + 2153};
long long mod[10];
long long val[10], cur[10];
char s[100];

int main() {
  scanf("%d%d", &n, &k);
  if(k == 0) {
    scanf("%s", s);
    if(s[0] == '?') {
      int cnt = 0;
      for(int i = 0; i<n; i++) {
        scanf("%s", s);
        if(s[0] != '?')
          cnt++;
      }
      puts((cnt & 1) ? "Yes" : "No");
    }
    else {
      int a = atoi(s);
      if(a)
        puts("No");
      else
        puts("Yes");
    }
    return 0;
  }
  for(int i = 0; i<8; i++) {
    mod[i] = (long long)dmod[i];
    val[i] = 0;
    cur[i] = 1;
  }
  for(int i = 0; i<=n; i++) {
    scanf("%s", s);
    if(s[0] == '?') {
      puts((n & 1) ? "Yes" : "No");
      return 0;
    }
    int a = atoi(s);
    for(int j = 0; j<8; j++) {
      val[j] = (val[j] + cur[j] * (long long)a) % mod[j];
      if(val[j] < 0)
        val[j] += mod[j];
      cur[j] = (cur[j] * k) % mod[j];
    }
  }
  bool ok = true;
  for(int i = 0; i<8; i++) {
    val[i] %= mod[i];
    if(val[i] != 0)
      ok = false;
  }
  puts(ok ? "Yes" : "No");
  return 0;
}