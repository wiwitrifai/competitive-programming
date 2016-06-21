#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5, base = 1e8;
char s[N];
struct big {
  vector< long long > val;
  big(char s[]) {
    int n = strlen(s);
    for(int i = n-1; i>=0; i-=8) {
      int k = max(i-7, 0);
      int now = 0;
      for(int j = k; j<=i; j++) {
        now *= 10;
        now += s[j]-'0';
      }
      val.push_back(now);
    }
  }
  int ddiv(int w) {
    long long now = 0;
    for(int i = (int)val.size()-1; i>=0; i--) {
      now *= base;
      now += val[i];
      val[i] = now/w;
      if(val[i] > base) {
        val[i+1] += val[i]/base;
        val[i] %= base;
      }
      now %= w;
    }
    while(!val.empty() && val.back() == 0)
      val.pop_back();
    return now;
  }
  void mul(int w) {
    long long now = 0;
    for(int i = 0; i<val.size(); i++) {
      now = 1LL* val[i] * w + now;
      val[i] = now % base;
      now /= base;
    }
    while(now) {
      val.push_back(now % base);
      now /= base;
    }
  }
  void print() {
    if(val.empty()) {
      printf("0");
      return;
    }
    printf("%d", val.back());
    for(int i = (int)val.size()-2; i>=0; i--)
      printf("%08d", val[i]);
  }
};
char t[] = "2";
int main() {
  freopen("strange.in", "r", stdin);
  freopen("strange.out", "w", stdout);
  long long pw = 1;
  while(pw * 2 < base)
    pw <<= 1;
  scanf("%s", s);
  big b(s);
  big ans(t);
  long long res = 0;
  while(res == 0) {
    res = b.ddiv(pw);
    if(res == 0)
      ans.mul(pw);
    else
      ans.mul(res & (-res));
  }
  ans.print();
  printf("\n");
  return 0;
}