#include <bits/stdc++.h>

using namespace std;

long long gcd(long long num, long long b) {
  return b? gcd(b, num % b) : num;
}

long long num[3];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    long long n, m;
    scanf("%lld %lld", &n, &m);
    for(int i = 0; i < 3; i++) scanf("%lld", num + i);
    long long sum = num[0] + num[1] + num[2];
    if(sum != n * m) {
      puts("No");
      continue;
    }
    if((num[0] % n) == 0 && (num[1] % n) == 0 && (num[2] % n) == 0) {
      puts("Yes");
      continue;
    }
    if((num[0] % m) == 0 && (num[1] % m) == 0 && (num[2] % m) == 0) {
      puts("Yes");
      continue;
    }
    bool found = 0;
    for(int i = 0; i < 2; i++) {
      sort(num, num + 3);
      for(int j = 0; j<3; j++) {
        long long a = num[(j) % 3];
        long long b = num[(j+1) % 3];
        long long c = num[(j+2) % 3];

        long long s = a + b;
        if((s % m) == 0 && (c % m) == 0) {
          long long nn = s/m;
          if(nn > 0 && (a % nn) == 0 && (b % nn) == 0) {
            found = 1;
          }
        }
      }
      swap(n, m);
    }
    puts(found? "Yes" : "No");
  }
  return 0;
}