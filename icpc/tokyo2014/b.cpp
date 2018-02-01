#include <bits/stdc++.h>

using namespace std;

const int N = 20;

char s[N];
bool alive[N];
long long num[N];

long long lef_to_rig() {
  int n = strlen(s);
  long long now = s[0] - '0';
  for (int i = 2; i < n; i += 2) {
    if (s[i-1] == '*') {
      now = now * (s[i] - '0');
    } else {
      now = now + (s[i] - '0');
    }
  }
  return now;
}

long long multi() {
  int n = strlen(s);
  fill(alive, alive + n, 1);
  for (int i = 0; i < n; i++) {
    if (s[i] == '*' || s[i] == '+') {
      alive[i] = 0;
    } else {
      num[i] = s[i] - '0';
      //printf("%d\n", num[i]);
    }
  }
  for (int i = 0; i < n; i++) {
    //printf("asu %c\n", s[i]);
    if (s[i] == '*') {
      alive[i-1] = 0;
      //printf("num %lld %lld\n", num[i - 2], num[i]);
      num[i+1] = num[i-1] * num[i+1]; 
    }
  }
  //puts("kali done");
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (alive[i]) {
      ans += num[i];
    }
  }
  return ans;
}

long long v;

int main() {
  scanf("%s %lld", s, &v);
  long long lef = lef_to_rig();
  long long mul = multi();
  //printf("%lld %lld\n", lef, mul);
  if (v == lef && v == mul) {
    puts("U");
  } else if (v == lef) {
    puts("L");
  } else if (v == mul) {
    puts("M");
  } else {
    puts("I");
  }
  return 0;
}