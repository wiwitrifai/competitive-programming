#include <bits/stdc++.h>

using namespace std;
const int N = 3e5 + 5;
char s[N], a[N], b[N];


int main() {
  scanf("%s", s);
  int n = strlen(s);
  bool isint= s[0] <= '9' && s[0] >= '0';
  int now = 0, na = 0, nb = 0;
  int last = 0;
  for(int i = 0; i<n; i++) {
    if(s[i] == ',' | s[i] == ';') {
      if(isint) {
        while(last < i) {
          a[na++] = s[last++];
        }
        a[na++] = ',';
      }
      else {
        while(last < i) {
          b[nb++] = s[last++];
        }
        b[nb++] = ',';
      }
      isint = s[i+1] <= '9' && s[i+1] >= '0';
      now = 0;
      last++;
    }
    else {
      if(isint) {
        if(s[i] > '9' || s[i] < '0')
          isint = false;
        else {
          if(i == last+1 && s[last] ==  '0')
            isint = false;
        }
      }
    }
  }
  if(isint) {
    while(last < n) {
      a[na++] = s[last++];
    }
    a[na++] = ',';
  }
  else {
    while(last < n) {
      b[nb++] = s[last++];
    }
    b[nb++] = ',';
  }
  if(na) {
    if(na && a[na-1] == ',') {
      na--;
    }
    a[na] = '\0';
    printf("\"%s\"\n", a);
  }
  else
    puts("-");

  if(nb) {
    if(nb && b[nb-1] == ',') {
      nb--;
    }
    b[nb] = '\0';
    printf("\"%s\"\n", b);
  }
  else
    puts("-");
  return 0;
}