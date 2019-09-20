#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

char s[N];
bool ok[256];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  for (int i = 0; i < n; ++i) {
    int now = s[i] - 'a';
    bool ans = 0;
    for (int j = 0; j < now; ++j)
      ans |= ok[j];
    ok[now] = 1;
    puts(ans ? "Ann" : "Mike");
  }
  return 0;
}
