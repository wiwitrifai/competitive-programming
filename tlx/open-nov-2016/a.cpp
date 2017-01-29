#include <bits/stdc++.h>

using namespace std;

string to[256];
int from[256];


int main() {
  to[0] = "A";
  for (int i = 1; i < 9; i++) {
    to[i] = "";
    to[i].push_back('1' + i);
  }
  to[9] = "10";
  to[10] = "J";
  to[11] = "Q";
  to[12] = "K";
  int t;
  scanf("%d", &t);
  while (t--) {
    char s[10];
    scanf("%s", s);
    int len = strlen(s);
    char cc = s[len-1];
    int now = 0;
    if (s[0] == 'J')
      now = 10;
    else if (s[0] == 'Q')
      now = 11;
    else if (s[0] == 'K')
      now = 12;
    else if (s[0] == 'A')
      now = 0;
    else if (len > 2)
      now =  9;
    else
      now = s[0] - '1';
    int cnt = 12;
    for (int i= now+1; i < 13; i++) {
      cnt--;
      cout << to[i] << cc;
      if (cnt)
        cout << " ";
      else
        cout << endl;
    }

    for (int i= now-1; i >= 0; i--) {
      cnt--;
      cout << to[i] << cc;
      if (cnt)
        cout << " ";
      else
        cout << endl;
    }
  }
  return 0;
}