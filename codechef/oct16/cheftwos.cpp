#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, mod = 1e9 + 7;

char a[N], b[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s %s", a, b);
    int n = strlen(a);
    n--;
    int i = 0, j = 0;
    long long ans = 2;
    while (i < n || j < n) {
      // cerr << i << " " << j << endl;
      if (i <= j) {
        if (a[i] == '2') {
          if (i + 3 > n) {
            ans = 0;
            break;
          }
          i++;
          if (a[i] == '1') {
            if (i < j) {
              ans = 0;
              break;
            }
            else {
              swap(a[i], b[i]);
              if (a[i] != '2') {
                ans = 0;
                break;
              }
            }
          }
          i++;
          if (a[i] == '2') {
            if (i < j) {
              ans = 0;
              break;
            }
            else {
              swap(a[i], b[i]);
              if (a[i] != '1') {
                ans = 0;
                break;
              }
            }
          }
        }
        i++;
      }
      else {
        if (b[j] == '2') {
          // cerr << j + 3 << endl;
          if (j + 3 > n) {
            ans = 0;
            break;
          }
          j++;
          // cerr << j << endl;
          if (b[j] == '1') {
            if (i > j) {
              ans = 0;
              break;
            }
            else {
              swap(a[j], b[j]);
              if (b[j] != '2') {
                ans = 0;
                break;
              }
            }
          }
          j++;
          // cerr << j << endl;
          if (b[j] == '2') {
            if (i > j) {
              ans = 0;
              break;
            }
            else {
              swap(a[j], b[j]);
              if (b[j] != '1') {
                ans = 0;
                break;
              }
            }
          }
        }
        j++;
      }
    }
    // cerr << a << " " << b << endl;
    bool mul = false;
    for (int i = 0; i < n; i++) {
      if (a[i] == '1' && b[i] == '1') {
        ans = (ans * 2) % mod;
        if (mul) {
          ans = (ans * 2) % mod;
          mul = false;
        }
      }
      else if (a[i] == '2' && b[i] == '2') {
        ans = (ans * 2) % mod;
      }
      else
        mul = true;
    }
    printf("%lld\n", ans);
  }
  return 0;
}