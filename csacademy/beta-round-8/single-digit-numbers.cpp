#include <bits/stdc++.h>

using namespace std;

int get(int a) {
  int ret = 0;
  for (int i = 1; i <= 9; i++) {
    int now = i;
    while(now <= a) {
      ret++;
      now = now * 10 + i;
    }
  }
  return ret;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << get(b) - get(a-1) << endl;
    return 0;
}