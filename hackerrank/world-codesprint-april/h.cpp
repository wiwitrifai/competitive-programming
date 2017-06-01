#include <bits/stdc++.h>

using namespace std;

const int N = 5005;

int dp[N];
pair<int, int> sol[N];
int a[N], b[N], c[N], back[N], q;

int solve(int x) {
  if(x == 0)
    return 0;
  if(dp[x])
    return dp[x];
  dp[x] = N;
  back[x] = 1;
  for(int i = 1; i<=x; i++) {
    int res = solve(x-i) + a[i] + b[i] + c[i];
    if(res < dp[x]) {
      back[x] = i;
      dp[x] = res;
    }
  }
  dp[x] += (q & 1) ? (q-1)/2 * 3 : (q-2)/2*3 + 1;
  return dp[x];
}

int main() {
  for(int i = 1; i<N; i++) {
    int x = 1, y = i;
    for(int j = 2; j<=i; j++) if(i % j == 0) {
      if(x + y > j + i/j) {
        x = j;
        y = i/j;
      }
    }
    sol[i] = make_pair(x, y);
  }
  for(int i = 1; i<N; i++) {
    int x = 1;
    for(int j = 2; j<=i; j++) if(i % j == 0) {
      if(x + sol[i/x].first + sol[i/x].second > j + sol[i/j].first + sol[i/j].second)
        x = j;
    }
    a[i] = x;
    b[i] = sol[i/x].first;
    c[i] = sol[i/x].second;
  }
  int p;
  scanf("%d%d", &p, &q);
  if(q > 2) {
    int node = solve(p);
    int n = node, m = node;
    if((q & 1) == 0) {
      int tmp = p;
      while(tmp) {
        m--;
        tmp -= back[tmp];
      }
    }
    int now = 1;
    printf("%d %d\n", n, m);
    if(q & 1) {
      while(p) {
        printf("%d %d\n", now, now+1);
        printf("%d %d\n", now+1, now+2);
        printf("%d %d\n", now, now+2);
        now += 3;
        int sz = ((q-1)/2)*3 - 3;
        for(int i = 0; i<sz; i++) {
          printf("%d %d\n", now, now-3);
          now++;
        }
        int cen = now-3;
        for(int i = 0; i<a[back[p]]; i++) {
          printf("%d %d\n", now, cen);
          now++;
        }
        for(int i = 0; i<b[back[p]]; i++) {
          printf("%d %d\n", now, cen+1);
          now++;
        }
        for(int i = 0; i<c[back[p]]; i++) {
          printf("%d %d\n", now, cen+2);
          now++;
        }
        p -= back[p];
      }
    }
    else {
      while(p) {
        printf("%d %d\n", now, now+1);
        printf("%d %d\n", now, now+2);
        printf("%d %d\n", now, now+3);
        now += 4;
        int sz = (q-2)/2*3 - 3;
        for(int i = 0; i<sz; i++) {
          printf("%d %d\n", now, now-3);
          now++;
        }
        int cen = now-3;
        for(int i = 0; i<a[back[p]]; i++) {
          printf("%d %d\n", now, cen);
          now++;
        }
        for(int i = 0; i<b[back[p]]; i++) {
          printf("%d %d\n", now, cen+1);
          now++;
        }
        for(int i = 0; i<c[back[p]]; i++) {
          printf("%d %d\n", now, cen+2);
          now++;
        }
        p -= back[p];
      }
    }
  }
  else {
    int ver = 33;
    int n = 0, m = 0;
    int tmp = p;
    while(tmp) {
      if(ver*(ver-1)*(ver-2)/6 > tmp) {
        ver--;
        continue;
      }
      n += ver+1;
      m += ver;
      tmp -= ver*(ver-1)*(ver-2)/6;
    }
    printf("%d %d\n", n, m);
    int now = 1;
    tmp = p;
    ver = 33;
    while(tmp) {
      if(ver*(ver-1)*(ver-2)/6 > tmp) {
        ver--;
        continue;
      }
      for(int i = 1; i<=ver; i++)
        printf("%d %d\n", now, now+i);
      now += ver+1;
      tmp -= ver*(ver-1)*(ver-2)/6;
    }
  }
  return 0;
}