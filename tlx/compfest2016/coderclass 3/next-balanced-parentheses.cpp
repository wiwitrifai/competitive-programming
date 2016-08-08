#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

char s[N];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%s", s);
    int n = strlen(s);
    int a, b;
    a = b = 0;
    bool ok = false;
    for(int i = n-1; i>0; i--) {
      if(s[i] == ')' && s[i-1] == '(' && a < b) {
        swap(s[i], s[i-1]);
        for(int j = 0; j<a; j++)
          s[i+j+1] = '(';
        for(int j = 0; j<b; j++)
          s[i+a+j+1] = ')';
        ok = true;
        break;
      }
      a += (s[i] == '(');
      b += (s[i] == ')');
    }
    puts(ok ? s : "TIDAK ADA");
  }

  return 0;
}