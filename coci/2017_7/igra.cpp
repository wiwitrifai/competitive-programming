#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
char s[N], t[N];

int main() {
  int n;
  scanf("%d %s %s", &n, t, s);
  int a[4], b[4];
  memset(a, 0, sizeof a);
  memset(b, 0, sizeof b);
  for (int i = 0; i < n; i++) {
    s[i] -= 'a';
    t[i] -= 'a';
    a[s[i]]++;
    b[t[i]]++;
  }
  for (int i = 0; i < n; i++) {
    a[s[i]]--;
    for (int j = 0; j < 3; j++) {
      if (s[i] == j || b[j] == 0) continue;
      b[j]--;
      if (b[0]+b[1] < a[2] || b[0]+b[2] < a[1] || b[1]+b[2] < a[0]) {
        b[j]++;
        continue;
      }
      printf("%c", j + 'a');
      break;
    }
  }
  printf("\n");
  return 0;
}