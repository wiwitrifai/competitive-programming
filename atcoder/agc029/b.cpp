#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &a[i]);
  sort(a.begin(), a.end());
  int ans = 0;
  for (int sum = 1 << 30; sum > 1; sum >>= 1) {
    vector<int> depan, belakang;
    int i = 0, j = (int)a.size()-1;
    while (i < j) {
      if (a[i] + a[j] == sum) {
        ++i, --j;
        ++ans;
      }
      else if (a[i] + a[j] < sum)
        depan.push_back(a[i++]);
      else
        belakang.push_back(a[j--]);
    }
    if (i == j)
      depan.push_back(a[i]);
    for (int k = (int)belakang.size()-1; k >= 0; --k)
      depan.push_back(belakang[k]);
    a.swap(depan);
  }
  printf("%d\n", ans);
  return 0;
}