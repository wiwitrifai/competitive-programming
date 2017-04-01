#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 6;

char s[N];
bool used[N];
vector< int > id[3];

int main() {
  scanf("%s", s);
  int n = strlen(s);
  for (int i = 0; i < n; i++) {
    char c = (s[i]-'0') % 3;
    if (c == 0)
      used[i] = 1;
    else {
      id[c].push_back(i);
    }
  }
  int r = (id[1].size() * 1 + id[2].size() * 2) % 3;
  if (r == 0) {
    printf("%s\n", s);
    return 0;
  }
  if (id[r].size() > 0) {
    int rem = -1;
    if (id[r].size() == 1) {
      if (id[r][0] != 0)
        rem = id[r][0];
      else if (n > 1 && s[1] != '0')
        rem = id[r][0];
    }
    else
      rem = id[r].back();
    if (rem != -1) {
      for (int i = 0; i < n; i++) if (i != rem) {
        printf("%c", s[i]);
      }
      printf("\n");
      return 0;
    }
  }
  if (id[3-r].size() > 1) {
    int rem1 = id[3-r].back(), rem2 = id[3-r][id[3-r].size()-2];
    int k = 0;
    for (int i = 0; i < n; i++) {
      if (i == rem1 || i == rem2) continue;
      s[k++] = s[i];
    }
    s[k] = '\0';
    int off = 0;
    while (s[off] == '0' && off + 1 < k) off++;
    if (off >= k)
      puts("-1");
    else
      printf("%s\n", s+off);
    return 0;
  }
  if (id[r].size() > 0 && id[r][0] == 0) {
    int off = 1;
    while (off + 1 < n && s[off] == '0') off++;
    if (off >= n)
      puts("-1");
    else
      printf("%s\n", s+off);
    return 0;
  }
  return 0;
}