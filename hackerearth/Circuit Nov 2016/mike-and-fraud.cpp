#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N];
vector< int > prime, cnt;

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 2; 1LL * i * i <= k; i++) if ((k % i) == 0) {
    int tmp = 0;
    while ((k % i) == 0) {
      tmp++;
      k /= i;
    }
    prime.push_back(i);
    cnt.push_back(-tmp);
  }
  if (k > 1) {
    prime.push_back(k);
    cnt.push_back(-1);
  }
  long long ans = 0;
  int last = 0, need = cnt.size();
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
    int now = a[i];
    for (int j = 0; j < prime.size(); j++) {
      int tmp = 0;
      while ((now % prime[j]) == 0) now /= prime[j], tmp++;
      if (cnt[j] < 0 && cnt[j] + tmp >= 0)
        need--;
      cnt[j] += tmp;
    }
    if (!need) {
      bool ok = true;
      while (ok) {
        now = a[last];
        for (int j = 0; j < prime.size(); j++) {
          int tmp = 0;
          while ((now % prime[j]) == 0) now /= prime[j], tmp++;
          if (tmp >  cnt[j]) {
            ok = false;
            break;
          }
        }
        if (ok) {
          now = a[last];
          for (int j = 0; j < prime.size(); j++) {
            int tmp = 0;
            while ((now % prime[j]) == 0) now /= prime[j], tmp++;
            cnt[j] -= tmp;
          }
          last++;
        }
      }
      ans += last+1;
    }
  }
  printf("%lld\n", ans);
  return 0;
}