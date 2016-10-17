#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

struct BIT {
  long long a[N];
  BIT() {
    memset(a, 0, sizeof a);
  }
  void upd(int x, long long v) {
    for (; x < N; x += x&(-x))
      a[x] += v;
  }
  long long get(int x) {
    x = min(x, N-1);
    long long ret = 0;
    for(; x; x -= x&(-x))
      ret += a[x];
    return ret;
  }


};
int cnt[N];
BIT prog;
BIT flat; 

int  main() {
  int n;
  scanf("%d", &n);
  int ma = 0;
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    ma = max(ma, a);
    cnt[a]++;
    sum += a;
  }
  long long mi = sum;
  for (int i = 1; i <= ma; i++) if (cnt[i]) {
    prog.upd(i, 1LL * cnt[i] * i);
    flat.upd(i, cnt[i]);
  } 
  for (int i = 1; i <= ma; i++) if (cnt[i]) {
    long long now = 0;
    for (int j = 0; j <= ma; j += i) {
      long long sp = prog.get(j + i-1) - prog.get(j), sf = flat.get(j + i - 1) - flat.get(j);
      now += sp - sf * j;
    } 
    if (now < mi)
      mi = now;
  }
  cout << sum - mi << endl;
  return 0;
}