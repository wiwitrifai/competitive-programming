#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;
const int mod = 1e9 + 9;

char s1[N], s2[N], s3[N];
long long suf1[N], suf2[N], suf3[N], suf12[N], suf23[N];

int Less(char a, char b) {
  if(a == '?' && b == '?')
    return 13*25;
  if(a != '?' && b != '?')
    return a < b ? 1 : 0;
  if(a == '?')
    return max(0, b - 'a');
  return 'z' - a;
}
int equal(char a, char b) {
  if(a == '?' && b == '?')
    return 26;
  if(a != '?' && b != '?')
    return a == b ? 1 : 0;
  return 1;
}
int LessLess(char a, char b, char c) {
  int a1 = (a == '?') ? 'a' : a;
  int a2 = (a == '?') ? 'z' : a;
  int b1 = (b == '?') ? 'a' : b;
  int b2 = (b == '?') ? 'z' : b;
  int c1 = (c == '?') ? 'a' : c;
  int c2 = (c == '?') ? 'z' : c;
  int ret = 0;
  for(int i = b1; i<=b2; i++) {
    ret += max(0, min(i, a2+1) - a1 )*max(0, c2 - max(c1-1, i));
  }
  return ret;
}
int Lessequal(char a, char b, char c) {
  if(b != '?' && c != '?' && b != c)
    return 0;
  if(b == '?')
    return Less(a, c);
  else
    return Less(a, b);
}
int equalLess(char a, char b, char c) {
  if(a != '?' && b != '?' && a != b)
    return 0;
  if(a == '?')
    return Less(b, c);
  else
    return Less(a, c);
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%s%s%s", s1, s2, s3);
    int n1 = strlen(s1), n2 = strlen(s2), n3 = strlen(s3);
    s1[n1] = s2[n2] = s3[n3] = 'a' - 1;
    suf1[n1+1] = 1;
    for(int i = n1; i>=0; i--)
      suf1[i] = (((s1[i] == '?') ? 26LL : 1) * suf1[i+1]) % mod;
    suf2[n2+1] = 1;
    for(int i = n2; i>= 0; i--)
      suf2[i] = ((s2[i] == '?' ? 26LL : 1) * suf2[i+1]) % mod;
    suf3[n3+1] = 1;
    for(int i = n3; i>=0; i--)
      suf3[i] = ((s3[i] == '?' ? 26LL : 1) * suf3[i+1]) % mod;
    suf12[min(n1, n2) + 1] = 0;
    for(int i = min(n1, n2); i>= 0; i--)
      suf12[i] = (1LL*equal(s1[i], s2[i]) * suf12[i+1] + 1LL*Less(s1[i], s2[i])*((1LL*suf1[i+1]*suf2[i+1]) % mod)) % mod;    
    suf23[min(n2, n3) + 1] = 0;
    for(int i = min(n2, n3); i>= 0; i--)
      suf23[i] = (1LL*equal(s2[i], s3[i]) * suf23[i+1] + 1LL*Less(s2[i], s3[i])*((1LL*suf2[i+1]*suf3[i+1]) % mod)) % mod;
    long long ans = 0;
    long long pref = 1;
    for(int i = 0; i<=min(n1, min(n2, n3)); i++) {
      long long now;
      now = pref;
      now = (now * LessLess(s1[i], s2[i], s3[i])) % mod;
      now = (now * suf1[i+1]) % mod;
      now = (now * suf2[i+1]) % mod;
      now = (now * suf3[i+1]) % mod;
      ans = (ans+now) % mod;

      now = pref;
      now = (now * equalLess(s1[i], s2[i], s3[i])) % mod;
      now = (now * suf12[i+1]) % mod;
      now = (now * suf3[i+1]) % mod;
      ans = (ans + now) % mod;

      now = pref;
      now = (now * Lessequal(s1[i], s2[i], s3[i])) % mod;
      now = (now * suf1[i+1]) % mod;
      now = (now * suf23[i+1]) % mod;
      ans = (ans + now) % mod;

      if(s1[i] == '?' && s2[i] == '?' && s3[i] == '?')
        pref = (pref*26) % mod;
      if((s1[i] != '?' && s2[i] != '?' && s1[i] != s2[i]) ||
         (s2[i] != '?' && s3[i] != '?' && s2[i] != s3[i]) ||
         (s3[i] != '?' && s1[i] != '?' && s3[i] != s1[i]))
      break;
    }
    printf("%lld\n", ans);
  }
  return 0;
}