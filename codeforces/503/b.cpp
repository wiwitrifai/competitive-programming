#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int val[N];
bool ok[N];
int n;

int pasang(int x) {
  return (x + n/2) % n;
}

int ask(int x) {
  x %= n;
  if (x < 0) x += n;
  if (ok[x]) return val[x];
  ok[x] = 1;
  int y = x;
  if (y <= 0) y += n;
  printf("? %d\n", y);
  fflush(stdout);
  scanf("%d", val+x);
  return val[x];
}

int calc(int x) {
  return ask(pasang(x)) - ask(x);
}

void done(int x) {
  x %= n;
  if (x == 0) x = n;
  printf("! %d\n", x);
  fflush(stdout);
  exit(0);
}

int main() {
  memset(ok, false, sizeof ok);
  scanf("%d", &n);
  if (n % 4) {
    done(-1);
    return 0;
  }
  int l = 0, r = n/2;
  if (calc(0) == 0)
    done(0);
  while (l + 1 < r) {
    int mid = (l + r) >> 1;
    int val = calc(mid);
    if (val == 0)
      done(mid);
    if (val < 0) {
      if (calc(l) < 0)
        l = mid;
      else
        r = mid;
    }
    else {
      if (calc(l) > 0)
        l = mid;
      else
        r = mid;
    }
  }
  for (int i = l; i <= r; ++i) {
    if (calc(i) == 0)
      done(i);
  }
  done(-1);
  return 0;
}