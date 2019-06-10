#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

int a[N];
int lef[N], rig[N];
int n;

long long hitung(int len, int l, int r) {
  long long ret = 1LL * len * (len + 1) / 2;
  if (l <= len) {
    long long now = len - l;
    ret -= 1LL * now * (now + 1) / 2;
  }
  if (r <= len) {
    long long now = len - r;
    ret -= 1LL * now * (now + 1) / 2;
  }
  if (l + r <= len) {
    long long now = len - l - r;
    ret += 1LL * now * (now + 1) / 2;
  }
  return ret;
}

long long calc(long long x) {
  if (x < 0)
    return 0;
  long long cnt = 0;
  for (int i = 0; i < n; ++i) {
    long long len = x / a[i];
    cnt += hitung(min(len, (long long)n), lef[i], rig[i]);
  }
  return cnt;
}

long long atleast(long long pos) {
  long long lo = 0, hi = 1LL * n * int(1e9);
  while (lo < hi) {
    long long mid = (lo + hi) >> 1;
    if (calc(mid) >= pos)
      hi = mid;
    else
      lo = mid + 1;
  }
  return lo;
}

vector<long long> ans;
void find(long long low, long long hig) {
  if (low > hig)
    return;
  for (int i = 0; i < n; ++i) {
    long long mil = (low + a[i] - 1) / a[i], mah = hig / a[i];
    if (mah < mil) continue;
    for (long long len = mil; len <= mah; ++len) {
      if (lef[i] + rig[i] - 1 < len) break;
      int from = max(-(long long)lef[i] + 1, -len+1), til = min(0LL, rig[i]-len);
      for (int j = from; j <= til; ++j)
        ans.push_back(1LL * a[i] * len);
    }
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
  }
  stack<int> st;
  for (int i = 0; i < n; ++i) {
    while (!st.empty() && a[st.top()] >= a[i]) st.pop();
    lef[i] = st.empty() ? i+1 : i - st.top();
    st.push(i);
  }
  while (!st.empty()) st.pop();
  for (int i = n-1; i >= 0; --i) {
    while (!st.empty() && a[st.top()] > a[i]) st.pop();
    rig[i] = st.empty() ? n-i : st.top() - i;
    st.push(i);
  }
  long long l, r;
  scanf("%lld %lld", &l, &r);
  long long low = atleast(l), high = atleast(r);
  if (low == high) {
    for (int i = 0; i < r-l+1; ++i) {
      printf("%lld%c", low, i == (r-l) ? '\n' : ' ');
    }
    return 0;
  }
  long long cnt = calc(low);
  for (long long i = l; i <= cnt; ++i)
    ans.push_back(low);
  cnt = calc(high-1);
  for (long long i = cnt+1; i <= r; ++i)
    ans.push_back(high);
  find(low+1, high-1);
  sort(ans.begin(), ans.end());
  for (int i = 0; i < (int)ans.size(); ++i)
    printf("%lld%c", ans[i], i+1 == (int)ans.size() ? '\n' : ' ');
  return 0;
}
