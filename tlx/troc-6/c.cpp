#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char s[N];

bool used[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  scanf("%s", s);
  vector<int> ans;
  for (int i = 1; i < n; ++i) {
    if (s[i] == '0' || used[i-1] || s[i-1] == '0') continue;
    used[i] = 1;
    ans.push_back(i);
  }
  for (int i = 0; i < n; ++i) {
    if (used[i] || s[i] == '0') continue;
    ans.push_back(i);
  }
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1') continue;
    int j = i;
    while (j < n && s[j] == s[i]) ++j;
    int now = i + (i != 0);
    while (now < j-1) {
      ans.push_back(now);
      now += 2;
    }
    if (j == n && now == n-1)
      ans.push_back(now);
    i = j;
  }
  reverse(ans.begin(), ans.end());
  int add = (int)ans.size() - m;
  printf("%d\n", (int)ans.size() + add);
  for (int i = 0; i < ans.size(); ++i) {
    printf("1 %d\n", ans[i]+1);
  }
  for (int i = 0; i < add; ++i)
    printf("2\n");
  return 0;
}
