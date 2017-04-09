#include <bits/stdc++.h>

using namespace std;

char s[50];

int main() {
  int t;
  scanf("%d", &t);
  set< long long > st;
  while(t--) {
    scanf("%s", s);
    int n =strlen(s);
    if(s[0] != '1' && s[n-1] != '1') {
      printf("%s WRONG\n", s);
      continue;
    }
    for(int i = 2; i<=10; i++) {
      long long dv;
      scanf("%lld", &dv);
      long long val = 0;
      for(int j = 0; j<n; j++) {
        val *= i;
        val += s[j] - '0';
      }
      if(i == 2) {
        if(st.count(val))
          printf("%s REDUNDANT\n", s);
        st.insert(val);
      }
      if(val % dv) {
        printf("%s WRONG %d %lld mod %lld = %lld\n", s, i, val, dv, val % dv);
      }
    }
    // printf("%s DONE\n",s);
  }
  return 0;
}