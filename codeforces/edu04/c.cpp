#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

char s[N], inv[256];
int st[N], top;

int main() {
  inv['<'] = '>';
  inv['{'] = '}';
  inv['['] = ']';
  inv['('] = ')';
  top = -1;
  scanf("%s", s);
  int n = strlen(s);
  int ans = 0;
  for(int i = 0; i<n; i++) {
    if(s[i] == '<' || s[i] == '{' || s[i] == '[' || s[i] == '(')
      st[++top] = i;
    else {
      if(top < 0) {
        puts("Impossible");
        return 0;
      }
      if(s[i] != inv[s[st[top]]]) {
        ans++;
      }
      top--;
    }
  }
  if(top >= 0) {
    puts("Impossible");
    return 0;
  }
  cout << ans << endl;
  return 0;
}