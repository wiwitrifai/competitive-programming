#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5;

struct  node {
  node * to[26];
  int cnt;
  int leave;
  node(int lv) : cnt(1), leave(lv) {
    memset(to, NULL, sizeof to);
  }
};

int n;
char s[N];

int main() {
  scanf("%d", &n);
  node * root = new node(0);
  for(int i = 0; i<n; i++) {
    scanf("%s", s);
    int m = strlen(s);
    node * now = root;
    for(int j = 0; i<m; i++) {
      int x = s[j] - 'a';
      if(now->to[x]) {
        now->cnt++;
        now = now->to[x];
      }
      else {
        now->to[x] = new node(i == m-1);
        now = now->to[x];
      }
    }
    node * now = root;
    int st = 0;
    while(n--) {
      bool leave = false;
      now = root;
      while(now->cnt < 2)
      while(true) {
        if(leave) {
          if(now->leave) {
            
          }
        }
      }
    }
  }
  return 0;
}