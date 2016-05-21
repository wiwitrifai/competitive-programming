#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

char a[N], b[N];
int ca[30];

int main() {
  int tt;
  scanf("%d", &tt);
  while(tt--) {
    scanf("%s%s", a, b);
    memset(ca, 0, sizeof ca);
    int n = strlen(a);
    for(int i = 0; i<n; i++)
      ca[a[i]-'a']++;
    n = strlen(b);
    bool ans = false;
    for(int i = 0; i<n; i++)
      if(ca[b[i]-'a']) {
        ans = true;
        break;
      }
    puts(ans ? "Yes" : "No");
  }
  return 0;
}