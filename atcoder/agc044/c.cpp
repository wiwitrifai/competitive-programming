#include <bits/stdc++.h>

using namespace std;

const int N = 6e5 + 5;

char s[N];
int p[N], from[N], last[N];
int dig[N];

int main() {
  int n;
  scanf("%d", &n);
  scanf("%s", s);
  int len = strlen(s);
  int pw = 1;
  fill(last, last+len, 0);
  for (int i = 0; i < n; ++i) {
    bool swapped = false;
    for (int j = 0; j < pw; ++j) {
      dig[j] = 0;
      dig[pw + j] = 1;
      dig[pw * 2 + j] = 2;
    }
    for (int j = 0; j < len; ++j) {
      if (s[j] == 'S') {
        swapped = !swapped;
      } else {
        int add = 0;
        for (int k = 0; k < 3; ++k) {
          int now = k * pw + last[j];
          if (swapped) {
            if (dig[now] == 1)
              add = k;
            if (dig[now] == 0)
              dig[now] = 2;
            else if (dig[now] == 1)
              dig[now] = 0;
            else
              dig[now] = 1;
          } else {
            if (dig[now] == 2)
              add = k;
            dig[now] = (dig[now] + 1) % 3;
          }
        }
        last[j] += add * pw;
      }
    }
    for (int j = 0; j < pw; ++j) {
      int now = p[j];
      for (int k = 0; k < 3; ++k) {
        int cur = j + k * pw;
        if (swapped && dig[cur] != 0) {
          dig[cur] = 3 - dig[cur];
        }
        p[cur] = now + dig[cur] * pw;
      }
    }
    pw *= 3;
  }
  for (int i = 0; i < pw; ++i) {
    printf("%d%c", p[i], i+1 == pw ? '\n' : ' ');
  }
  return 0;
}
