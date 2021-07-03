#include <bits/stdc++.h>


using namespace std;

char s[33];
bool ada[11];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", s);
    int n = strlen(s);
    memset(ada, 0, sizeof ada);
    for (int i = 0; i < n; ++i) {
      ada[s[i] - '0'] = true;
    }
    puts(ada[0] && ada[1] && ada[2] ? "EUY" : "EDAN");
  }
  return 0;
}
