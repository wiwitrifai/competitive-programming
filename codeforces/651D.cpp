#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;
int n, a, b, t;
char s[N];

int main() {
  scanf("%d%d%d%d", &n, &a, &b, &t);
  scanf("%s", s);
  int ans = 0;
  long long now = 1 + (s[0] == 'w' ? b : 0);
  if(now > t) {
    puts("0");
    return 0;
  }
  int id = n-1;
  int cnt = 1;
  for(int i = 0; i<n; i++) {
    if(i) {
      now += a + 1 + (s[i] == 'w' ? b : 0);
      cnt++;
    }
    while(now <= t && id > i) {
      if(now + 1 + 2*a + (s[id] == 'w' ? b : 0) <= t) {
        now += 1 + 2*a + (s[id] == 'w' ? b : 0);
        id--;
        cnt++;
      }
      else
        break;
    }
    bool stop = false;
    while(now > t) {
      id++;
      if(id >= n)
        id -= n;
      now -= 1 + 2*a + (s[id] == 'w' ? b : 0);
      cnt--;
      if(id == 0) {
        stop = true;
        break;
      }
    }
    if(stop)
      break;
    ans = max(ans, min(cnt, n));
  }
  reverse(s+1, s+n);
  id = n-1;
  cnt = 1;
  now = 1 + (s[0] == 'w' ? b : 0);
  for(int i = 0; i<n; i++) {
    if(i) {
      now += a + 1 + (s[i] == 'w' ? b : 0);
      cnt++;
    }
    while(now <= t && id > i) {
      if(now + 1 + 2*a + (s[id] == 'w' ? b : 0) <= t) {
        now += 1 + 2*a + (s[id] == 'w' ? b : 0);
        id--;
        cnt++;
      }
      else
        break;
    }
    bool stop = false;
    while(now > t) {
      id++;
      if(id >= n)
        id -= n;
      now -= 1 + 2*a + (s[id] == 'w' ? b : 0);
      cnt--;
      if(id == 0) {
        stop = true;
        break;
      }
    }
    if(stop)
      break;
    ans = max(ans, min(cnt, n));
  }
  printf("%d\n", ans);
  return 0;
}