#include <iostream>

using namespace std;

const int N = 200;

int fib[N];
pair<pair<int, int>, int> st[N];

int main() {
  fib[0] = 1;
  fib[1] = 1;
  for (int i = 2; i < N; i++) {
    fib[i] = (fib[i-1] + fib[i-2]) % 10;
    st[i] = {{fib[i-1], fib[i-2]}, fib[i]};
  }
  int s = -1, c = 0;
  for (int i = 2; i < N && s == -1; i++) {
    for (int j = i+j; j < N && s == -1; j++) {
      if (st[i] == st[j]) {
        s = i;
        c = j - i;
      }
    }
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    if (n < N)
      printf("%d\n", fib[n]);
    else {
      int x = (n - s);
      x %= c;
      x += s;
      printf("%d\n", fib[x]);
    }
  }
  return 0;
}