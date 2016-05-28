#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;

char a[N], b[N];
int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%s%s", a, b);
    int n = strlen(a);
    for(int i = 0; i<n; i++) {
      if(a[i] == b[i])
        printf("%c", a[i] == 'W' ? 'B' : 'W');
      else
        printf("B");
    }
    printf("\n");
  }
  return 0;
}