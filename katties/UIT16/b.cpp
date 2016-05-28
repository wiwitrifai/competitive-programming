#include <bits/stdc++.h>

using namespace std;

string s;

int main() {
  int off = 0;
  while(getline(cin, s)) {
    if(s.empty()) {
      off = 0;
      printf("\n");
    }
    else {
      int cnt = 0;
      for(int i= 0; i<s.size(); i++)
        cnt += s[i] == '*';
      int beg = s.size() - off - cnt;
      int fin = s.size() - off;
      for(int i = 0; i<beg; i++)
        printf(".");
      for(int i = beg; i<fin; i++)
        printf("*");
      for(int i = fin; i<s.size(); i++)
        printf(".");
      printf("\n");
      off += cnt;
    }
  }

  return 0;
}