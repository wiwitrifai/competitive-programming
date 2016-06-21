#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N], b[N];
char s[N], cset[] = {'A', 'C', 'G', 'T'};
int idx[256];
bool isnot[N][5];

int main() {
  for(int i = 0; i<4; i++)
    idx[cset[i]] = i;
  int t;
  scanf("%d", &t);
  while(t--) {
    int n;
    scanf("%d", &n);
    for(int i = 0; i<n; i++) 
      scanf("%d", a+i);
    s[0] = cset[0];
    int now = 1;
    bool possible = true;
    memset(isnot, false, sizeof isnot);
    for(int i = 1; i<n; i++) {
      if((i + a[i]) > n)
        possible = false;
      if(!possible)
        break;
      while(now < (i + a[i])) {
        s[now] = s[now-i];
        now++;
      }
      isnot[i+a[i]][idx[s[a[i]]]] = true;
      if(now == i) {
        possible = false;
        for(int j = 0; j<4; j++)
          if(!isnot[i][j]) {
            s[now] = cset[j];
            possible = true;
            now++;
            break;
          }
      }
    }
    s[n] = '\0';
    b[0] = n;
    if(b[0] != a[0])
      possible = false;
    int l, r;
    l = r = 0;
    for(int i = 1; i<n && possible; i++) {
      if(i > r) {
        l = r = i;
        while(r < n && s[r-l] == s[r]) r++;
        b[i] = r-l; r--;
      }
      else {
        int k = i-l;
        if(b[k] < r-i+1)
          b[i] = b[k];
        else {
          l = i;
          while(r < n && s[r-l] == s[r]) r++;
          b[i] = r-l; r--;
        }
      }
      if(b[i] != a[i]) {
        possible = false;
        break;
      }
    }
    s[n] = '\0';
    printf("%s\n", possible ? s : "Impossible");
  }
  return 0;
}