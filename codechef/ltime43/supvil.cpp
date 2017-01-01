#include <bits/stdc++.h>

using namespace std;

char s[10000];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int score = 0;
    while (n--) {
      scanf("%s", s);
      if (score <= -3 || score >= 2)
        continue;
      int len = strlen(s);
      if (len < 3) {
        score--;
        continue;
      }
      if (s[len-1] == 'n' && s[len-2] == 'a' && s[len-3] == 'm')
        score++;
      else
        score--;
    }
    if (score >= 2)
      puts("superheroes");
    else if (score <= -3)
      puts("villains");
    else
      puts("draw");
  }
  return 0;
}