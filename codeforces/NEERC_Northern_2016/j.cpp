#include <bits/stdc++.h>

using namespace std;

int main() {
  freopen("java2016.in", "r", stdin);
  freopen("java2016.out", "w", stdout);
  int n;
  scanf("%d", &n);
  if (!n)
    puts("? /?/ ?");
  else {
    puts("a = ? max ?");
    for (int i = 0; i < 17; i++)
      printf("%c = %c max %c\n", 'a' + i+1, 'a' + i, 'a' + i);
    printf("%c = %c / %c\n", 'a' + 18, 'a' + 17, 'a' + 17);
    for (int i = 18; i < 25; i++) {
      printf("%c = %c + %c\n", 'a'+i+1, 'a'+i, 'a'+i);
    }
    int cnt = __builtin_popcount(n);
    for (int i = 0; i < 8; i++) if (n & (1<<i)) {
      printf("%c", 'a' + 18 + i);
      cnt--;
      if (cnt)
        printf(" + ");
    }
    printf("\n");
  }
  return 0;
}