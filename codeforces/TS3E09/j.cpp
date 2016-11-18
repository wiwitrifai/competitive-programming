#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 6, B = 1000000;
vector< int > val;
void mul(int x) {
  long long carry = 0;
  for (int & v : val) {
    carry += v * x;
    v = carry % B;
    carry /= B;
  }
  while (carry) {
    val.push_back(carry % B);
    carry /= B;
  }
}
void print() {
  printf("%d", val.back());
  for (int i = (int)val.size() - 2; i >= 0; i--)
    printf("%06d", val[i]);
}
int a[N], b[N];
bool used[N];
bitset< N > comp[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
    b[i] = a[i];
    comp[i].reset();
    comp[i][i] = 1;
  }
  for (int bit = 31; bit >= 0; bit--) {
    int now = -1;
    for (int i = 0; i < n; i++) {
      if (used[i])
        continue;
      if (a[i] & (1<<bit)) {
        now = i;
        break;
      }
    }
    if (now == -1)
      continue;
    used[now] = true;
    for (int i = 0; i < n; i++) {
      if (i == now)
        continue;
      if (a[i] & (1<<bit)) {
        a[i] ^= a[now];
        comp[i] = comp[i] ^ comp[now];
      }
    }
  }
  int s;
  s = 0;
  val.push_back(1);
  bitset < N > ans;
  ans.reset();
  for (int i = 0; i < n; i++) {
    if (a[i]) {
      s ^= a[i];
      ans = ans ^ comp[i];
    }
    else
      mul(2);
  }
  printf("%d ", s);
  print();
  int cnt = ans.count();
  printf(" %d\n", cnt);
  for (int i = 0; i < n; i++) if (ans[i])
    printf("%d%c", b[i], --cnt ? ' ' : '\n');
  return 0;
}