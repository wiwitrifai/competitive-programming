#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

long long a[N], b[N];

int main() {
  int n;
  long long m;
  scanf("%d %lld", &n, &m);
  for (int i = 0; i < n; ++i)
    scanf("%lld", a+i);
  int solve = a[0] <= m;
  for (int i = 1; i < n; ++i) {
    a[i] += a[i-1];
    if (a[i] <= m)
      solve = i+1;
  }
  int enemy = 0;
  long long sum = 0; 
  for (int i = 0; i < n; ++i) {
    scanf("%lld", b+i);
    sum += b[i];
    if (sum <= m)
      enemy = i+1;
  }
  if (solve > enemy) {
    puts("0");
    return 0;
  }
  deque<pair<int, int> > st;
  bool found = 0;
  sum = 0;
  for (int i = 0, j = 0; i < solve; ++i) {
    sum += b[i];
    int cnt = 0;
    while (!st.empty() && b[st.back().first] < b[i]) {
      cnt += st.back().second;
      sum -= 1LL * b[st.back().first] * st.back().second;
      st.pop_back();
    }
    if (cnt > 0) {
      st.emplace_back(i, cnt);
      sum += 1LL * b[i] * cnt;
    }
    while (j < solve && a[j] <= sum) {
      st.emplace_back(i, 1);
      sum += b[i];
      ++j;
    }
    if (sum > m) {
      found = 1;
      break;
    }
  }
  if (!found) {
    puts("-1");
    return 0;
  }
  sum = 0;
  vector<long long > ans;
  for (int i = 0; i < enemy; ++i) {
    sum += b[i];
    while (!st.empty() && st.front().first == i) {
      for (int it = 0; it < st.front().second; ++it) {
        ans.push_back(sum);
        sum += b[i];
      }
      st.pop_front();
    }
  }
  while (!ans.empty() && ans.back() > m) {
    ans.pop_back();
  }
  printf("%d\n", (int)ans.size());
  for (int i = 0; i < ans.size(); ++i) {
    printf("%lld%c", ans[i], i+1==ans.size() ? '\n' : ' ');
  }
  return 0;
}