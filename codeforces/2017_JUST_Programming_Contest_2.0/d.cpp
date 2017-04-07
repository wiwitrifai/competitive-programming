#include <bits/stdc++.h>

using namespace std;

int n;
bool eng(char c) {
  return ((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z'));
}
bool dig(char c) {
  return c >= '0' && c <= '9';
}
bool sym(char c) {
  return c == '@' || c == '?' || c == '!';
}
char st[2100];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", st);
    int m = strlen(st);
    int e = 0, d = 0, s = 0;
    for (int j = 0; j < m; j++) {
      e += eng(st[j]);
      d += dig(st[j]);
      s += sym(st[j]);
    }
    if (e < 4)
      puts("The last character must be a letter.");
    else if (d < 4)
      puts("The last character must be a digit.");
    else if (s < 2)
      puts("The last character must be a symbol.");
    else
      puts("The last character can be any type."); 
  }
  return 0;
}