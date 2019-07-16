#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

char s[N];

int a[N];
deque<int> zero;

int main() {
  int n;
  scanf("%s", s);
  n = strlen(s);
  for (int i = 0; i < n; ++i)
    a[i] = s[i] - '0';
  for (int i = 0; i < n; ++i) {
    while (a[i] >= 2) {
      if (zero.empty()) {
        --a[i];
        ++a[i+1];
        zero.push_front(0);
      }
      else {
        int last = zero.back();
        if (last+1 == i) {
          zero.pop_back();
          ++a[i-1];
          a[i];
          ++a[i+1];
        }
        else {
        }
      }
    }
    if (a[i] == 0) {
      zero.push_back(i);
    }
  }
  return 0;
}