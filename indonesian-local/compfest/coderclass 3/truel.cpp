#include <bits/stdc++.h>

using namespace std;

const string cuk = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz()";
const int N = 5010;

int id(char a) {
  for(int i = 0; i < cuk.length(); i++) {
    if(cuk[i] == a) return i;
  }
  return -1;
}

char s[N][N];
char str[N];

int to[N];

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    memset(to, 0, sizeof(to));
    
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
      scanf("%s", str);
      int len = strlen(str);
      for(int j = 0; j < len; j++) {
        int d = id(str[j]);
        for(int k = 0; k < 6; k++) {
          s[i][j * 6 + k] = ((d & (1 << (5 - k)))? 1 : 0);
        }
      }
    }
    
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        if(s[i][j]) {
          to[j]++;
        }
      }
    }
    stack<int> topo;
    int cur = 0;
    for(int i = 0; i < n; i++) {
      if(to[i] == 0) {
        topo.push(i);
      }
    }
    while(!topo.empty()) {
      int now = topo.top();
      topo.pop();
      cur++;
      for(int i = 0; i < n; i++) {
        if(s[now][i]) {
          to[i]--;
          if(to[i] == 0) {
            topo.push(i);
          }
        }
      }
    }
    puts(cur == n? "MANA SERUNYA" : "SERU PISAN");
  }
  
  return 0;
}