#include <bits/stdc++.h>

using namespace std;

const long long inf = 1e18;

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    long long a, b, c, d;
    a = b = 0;
    c = d = inf;
    scanf("%d", &n);
    long long h, m;
    scanf("%lld%lld", &h, &m);
    while(--n > 0) {
      long long hh, mm;
      scanf("%lld%lld", &hh, &mm);
      long long dm = m - mm, dh = hh - h;
      int sign = 1;
      if(dm == 0) {
        if(h <= hh)
          d = b-1;
        if(h >= hh)
          c = a-1;
      }
      else if(dm > 0) {
        long long val = dh/dm;
        while(h + m * val < hh + mm * val)
          val++;
        while(h + m * val >= hh + mm * val)
          val--;
        c = min(c, val);
        while(h + m * val <= hh + mm * val)
          val++;
        b = max(b, val);
      }
      else {
        long long val = dh/dm;
        while(h + m * val < hh + mm * val)
          val--;
        while(h + m * val >= hh + mm * val)
          val++;
        a = max(a, val);
        while(h + m * val <= hh + mm * val)
          val--;
        d = min(d, val);
      }
      h = hh;
      m = mm;
      swap(a, b);
      swap(c, d);
    }
    if(a <= c && b <= d) {
      if(a > b) {
        swap(a, b);
        swap(c, d);
      }
      if(c +1 >= b) {
        if(d >= inf)
          printf("1\n%lld Inf\n", a);
        else
          printf("1\n%lld %lld\n", a, d);
      }
      else {
        printf("2\n%lld ", a);  
        if(c >= inf)
          puts("Inf");
        else
          printf("%lld\n", c);
        printf("%lld ", b);
        if(d >= inf)
          puts("Inf");
        else
          printf("%lld\n", d);
      }
    }
    else if(a <= c) {
      if(c >= inf)
        printf("1\n%lld Inf\n", a);
      else  
        printf("1\n%lld %lld\n", a, c);
    }
    else if(b <= d) {
      if(d >= inf)
        printf("1\n%lld Inf\n", b);
      else
        printf("1\n%lld %lld\n", b, d);
    }
    else {
      puts("0");
    }
  }
  return 0;
}