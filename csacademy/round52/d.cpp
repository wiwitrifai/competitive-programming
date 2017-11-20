#include <bits/stdc++.h>

using namespace std;

int ask(int x) {
  printf("%d\n", x);
  fflush(stdout);
  int res;
  scanf("%d", &res);
  return res;
}

bool ok[20];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int cnt = 0;
    for (int i = 0; i < 10; i++) {
      ok[i] = ask(i * 11);
      cnt += ok[i];
    }
    if (cnt == 2) {
      bool cek = 0;
      for (int i = 0; i < 10; i++) {
        if (!ok[i] && !ok[(i+1) % 10]) {
          cek = 1;
          assert(!ask((i * 11 + 1) % 100));
          break;
        }
      }
      assert(cek);
    }
    else {
      assert(cnt == 1);
      bool cek = 0;
      for (int i = 0; i < 10; i++) {
        if (ok[i]) {
          cek = 1;
          assert(ask((i * 11 + 10) % 100));
          break;
        }
      }
      assert(cek);
    }
  }
  return 0;
}