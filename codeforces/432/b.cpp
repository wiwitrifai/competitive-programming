#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 6;

int cnt[N];
long long sum[N];
int getc(int l, int r) {
  return cnt[r] - (l ? cnt[l-1] : 0);
}
long long gets(int l, int r) {
  return sum[r] - (l ? sum[l-1] : 0);
}
int main() {
  int n, x, y;
  scanf("%d %d %d", &n, &x, &y);
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    cnt[a]++;
  }
  for (int i = 1; i < N; i++) {
    sum[i] = sum[i-1] - 1LL * i * cnt[i];
    cnt[i] += cnt[i-1];
  }
  int ma = x/y;
  long long ans = 1e18;
  for (int step = 2; step < N; step++) {
    long long cur = 0;
    for (int i = step; i < N; i += step) {
      int le = max(i - ma, i - step+1);
      int cx = getc(i-step+1, le-1), cy = getc(le, i);
      cur += 1LL * cx * x + (1LL * cy * i + gets(le, i)) * y;
    }
    ans = min(ans, cur);
  }
  cout << ans << endl;
  return 0;
}