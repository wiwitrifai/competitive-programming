#include <bits/stdc++.h>

using namespace std;

set< string > st;
string s;

bool isEn(char c) {
  return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
}
char toLow(char c) {
  if('A' <= c && c <= 'Z')
    return c - 'A' + 'a';
  return c;
}
char sc[100005], ss[1000005];

int main() {
  while(getline(cin, s)) {
    int n = s.size(), l = 0;
    bool str = false;
    // cout << s << " hah" << endl;
    for(int i = 0; i<n; i++) {
      if(isEn(s[i])) {
        str = true;
        sc[i-l] = toLow(s[i]);
        ss[i-l] = s[i];
      }
      else {
        if(str) {
          sc[i-l] = '\0';
          ss[i-l] = '\0';
          string now = sc;
          // cout << ss << ' ' << sc << ' ' << now << endl;
          if(st.count(now))
            printf(".");
          else {
            st.insert(now);
            printf("%s", ss);
          }
        }
        printf("%c", s[i]);
        str = false;
        l = i+1;
      }
    }
    if(str) {
      sc[n-l] = '\0';
      ss[n-l] = '\0';
      string now = sc;
      if(st.count(now))
        printf(".");
      else {
        st.insert(now);
        printf("%s", ss);
      }
    }
    printf("\n");
  }
  return 0;
}