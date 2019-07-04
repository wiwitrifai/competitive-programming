#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

int x[N], y[N];
int r[N], c[N];

void solve() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d %d", x+i, y+i);
    r[x[i]] = i;
    c[y[i]] = i;
  }
  int left = 1, right = n;
  int bottom = n, top = 1;
  int left_bottom = 0, left_top = 0;
  int right_bottom = 0, right_top = 0;
  if (y[r[1]] == 1)
    ++left_top;
  if (y[r[1]] == n)
    ++right_top;
  if (y[r[n]] == 1)
    ++left_bottom;
  if (y[r[n]] == n)
    ++right_bottom;
  if (n == 1) {
    left_top = 1;
    left_bottom = right_top = right_bottom = 0;
  }
  int offr = 0, offc = 0;
  while (m--) {
    char cmd[3];
    scanf("%s", cmd);
    if (cmd[0] == '!') {
      long long ans = 1LL * (left_bottom - 1) * left_bottom / 2 +
                      1LL * (left_top - 1) * left_top / 2 +
                      1LL * (right_bottom - 1) * right_bottom / 2 +
                      1LL * (right_top - 1) * right_top / 2;
      printf("%lld\n", ans);
    }
    else {
      int k;
      scanf("%d", &k);
      if (cmd[0] == '?') {
        printf("%d %d\n", offr + min(bottom, max(top, x[k])), offc + min(right, max(left, y[k])));
      }
      else if (cmd[0] == 'L') {
        offc -= k;
        if (offc + right < 1) {
          offc = 1 - right;
        }
        while (left + offc < 1) {
          ++left;
          if (left == right) {
            left_top += right_top;
            right_top = 0;
            left_bottom += right_bottom;
            right_bottom = 0;
          }
          else {
            if (x[c[left]] <= top || top == bottom)
              ++left_top;
            else if (x[c[left]] >= bottom)
              ++left_bottom;
          }
        }
      }
      else if (cmd[0] == 'R') {
        offc += k;
        if (offc + left > n) {
          offc = n - left;
        }
        while (right + offc > n) {
          --right;
          if (left == right) {
            left_top += right_top;
            right_top = 0;
            left_bottom += right_bottom;
            right_bottom = 0;
          }
          else {
            if (x[c[right]] <= top || top == bottom)
              ++right_top;
            else if (x[c[right]] >= bottom)
              ++right_bottom;
          }
        }
      }
      else if (cmd[0] == 'U') {
        offr -= k;
        if (offr + bottom < 1) {
          offr = 1 - bottom;
        }
        while (top + offr < 1) {
          ++top;
          if (top == bottom) {
            left_top += left_bottom;
            left_bottom = 0;
            right_top += right_bottom;
            right_bottom = 0;
          }
          else {
            if (y[r[top]] <= left || left == right)
              ++left_top;
            else if (y[r[top]] >= right)
              ++right_top;
          }
        }
      }
      else {
        assert(cmd[0] == 'D');
        offr += k;
        if (offr + top > n) {
          offr = n - top;
        }
        while (bottom + offr > n) {
          --bottom;
          if (top == bottom) {
            left_top += left_bottom;
            left_bottom = 0;
            right_top += right_bottom;
            right_bottom = 0;
          }
          else {
            if (y[r[bottom]] <= left || left == right)
              ++left_bottom;
            else if (y[r[bottom]] >= right)
              ++right_bottom;
          }
        }
      }

    }
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
