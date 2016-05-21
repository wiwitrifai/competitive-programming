#include <bits/stdc++.h>

using namespace std;

char ss[30], st[30], ans1[30], ans2[30], ans3[30], ans4[30];

int main() {
  int t;
  scanf("%d", &t);
  for(int tc = 1; tc <= t; tc++) {
    scanf("%s%s", ss, st);
    printf("Case #%d: ", tc);
    int n = strlen(ss);
    ans1[n] = ans2[n] = '\0';
    bool ok = true;
    for(int i = 0; i<n; i++) {
      if(ss[i] == '?' && st[i] == '?')
        ans1[i] = ans2[i] = '0';
      else if(ss[i] == '?')
        ans1[i] = ans2[i] = st[i];
      else if(st[i] == '?')
        ans1[i] = ans2[i] = ss[i];
      else if(ss[i] == st[i])
        ans1[i] = ans2[i] = st[i];
      else {
        ok = false;
        break;
      }
    }
    if(ok) {
      printf("%s %s\n", ans1, ans2);
      continue;
    }
    long long l, r, x, y;
    x = -1; y = -1;
    ok = true;
    l = r = 0;
    for(int i = 0; i<n; i++) {
      l *= 10; r *= 10;
      if(ss[i] == '?' && st[i] == '?') {
        if(l == r)
          ans1[i] = ans2[i] = '0';
        else if(l < r) {
          l += 9;
          ans1[i] = '9';
          ans2[i] = '0';
        }
        else {
          r += 9;
          ans1[i] = '0';
          ans2[i] = '9';
        }
      }
      else if(ss[i] == '?') {
        if(l == r) {
          ans1[i] = st[i];
          l += st[i]-'0';
        }
        else if(l < r) {
          l += 9;
          ans1[i] = '9';
        }
        else {
          ans1[i] = '0';
        }
        ans2[i] = st[i];
        r += st[i]-'0';
      }
      else if(st[i] == '?') {
        if(l == r) {
          ans2[i] = ss[i];
          r += ss[i]-'0';
        }
        else if(l < r) {
          ans2[i] = '0';
        }
        else {
          r += '9';
          ans2[i] = '9';
        }
        ans1[i] = ss[i];
        l += ss[i]-'0';
      }
      else if(ss[i] <= st[i]) {
        l += ss[i] - '0';
        r += st[i] - '0';
        ans1[i] = ss[i];
        ans2[i] = st[i];
      }
      else {
        while(l >= r) {
          l /= 10; r/= 10;
          i--;
          if(i < 0)
            break;
          if(ss[i] == '?' && st[i] == '?') {
            l = (l / 10) * 10; r = (r/10)*10 + 1;
            ans1[i] = '0';
            ans2[i] = '1';
          }
          else if(ss[i] == '?') {
            if(st[i] != '9') {
              ss[i] = st[i] + 1;
              l = (l/10)*10 + ss[i] - '0';
            }
          }
          else if(ss[i] != '0') {
            st[i] = ss[i] - 1;
            r = (r/10)*10 + st[i] - '0';
          }
        }
        if(i < 0) {
          ok = false;
          break;
        }
      }
    }
    if(ok)
      x = l, r = y;
    ok = true;
    l = r = 0;
    for(int i = 0; i<n; i++) {
      cout << i << " " << l << ' ' << r << endl;
      l *= 10; r *= 10;
      if(ss[i] == '?' && st[i] == '?') {
        if(l == r)
          ans3[i] = ans4[i] = '0';
        else if(l < r) {
          l += 9;
          ans3[i] = '9';
          ans4[i] = '0';
        }
        else {
          r += 9;
          ans3[i] = '0';
          ans4[i] = '9';
        }
      }
      else if(ss[i] == '?') {
        if(l == r) {
          ans3[i] = st[i];
          l += st[i]-'0';
        }
        else if(l < r) {
          l += 9;
          ans3[i] = '9';
        }
        else {
          ans3[i] = '0';
        }
        ans4[i] = st[i];
        r += st[i]-'0';
      }
      else if(st[i] == '?') {
        if(l == r) {
          ans4[i] = ss[i];
          r += ss[i]-'0';
        }
        else if(l < r) {
          ans4[i] = '0';
        }
        else {
          r += '9';
          ans4[i] = '9';
        }
        ans3[i] = ss[i];
        l += ss[i]-'0';
      }
      else if(ss[i] >= st[i]) {
        l += ss[i] - '0';
        r += st[i] - '0';
        ans3[i] = ss[i];
        ans4[i] = st[i];
      }
      else {
        cerr << i << " " << l << " " << r << endl;
        while(l <= r) {
          l /= 10; r/= 10;
          // i--;
          // cerr << i << " " << l << " " << r << endl;
          if(i < 0)
            break;
          if(ss[i] == '?' && st[i] == '?') {
            l = (l / 10) * 10 + 1; r = (r/10)*10;
            ans3[i] = '1';
            ans4[i] = '0';
          }
          else if(ss[i] == '?') {
            if(st[i] != '0') {
              ss[i] = st[i] - 1;
              l = (l/10)*10 + ss[i] - '0';
            }
          }
          else if(ss[i] != '9') {
            st[i] = ss[i] + 1;
            r = (r/10)*10 + st[i] - '0';
          }
        }
        if(i < 0) {
          ok = false;
          break;
        }
      }
    }
    if(ok) {
      if(x > -1 && y > -1) {
        if(abs(x-y) < abs(l-r)) {
          ans1[n] = ans2[n] = '\0';
          printf("%s %s\n", ans1, ans2);
        }
        else {
          ans3[n] = ans4[n] = '\0';
          printf("%s %s\n", ans3, ans4);
        }
      }
      else {
        ans3[n] = ans4[n] = '\0';
        printf("%s %s\n", ans3, ans4);
      }
    }
    else {
      ans1[n] = ans2[n] = '\0';
      printf("%s %s\n", ans1, ans2);
    }
    cerr << "TC " << tc << endl;
  }
  return 0;
}