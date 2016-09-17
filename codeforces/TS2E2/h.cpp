#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 6;

char s[N];
int id[N];

int main() {
  int k;
  scanf("%d%s", &k, s);
  int n = strlen(s);
  for (int i = 0; i < n; i++) if (s[i] == '1') {
    int j = i % k;
    if (id[j]) {
      printf("%d %d\n", id[j], i+1);
      return 0;
    }
    j = (i + 1) % k;
    id[j] = i+1;
  }
  puts("0 0");

  return 0;
}