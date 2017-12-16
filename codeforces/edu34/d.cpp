// can you hack wifi? :p
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int a[N];
map<int, int> cnt;
int get(int x) {
  auto it = cnt.find(x);
  if (it == cnt.end())
    return 0;
  return it->second;
}

int main() {
  int n;
  scanf("%d", &n);
  unsigned long long pos = 0, neg = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    int cur = get(a[i]-1) + get(a[i]) + get(a[i]+1);
    pos += 1LL * a[i] * (i - cur);
    cnt[a[i]]++;
  }
  cnt.clear();
  for (int i = n-1; i >= 0; --i) {
    int cur = get(a[i]-1) + get(a[i]) + get(a[i]+1);
    neg += 1LL * a[i] * ((n-1-i) - cur);
    cnt[a[i]]++;
  }
  if (pos >= neg)
    cout << pos - neg << endl;
  else
    cout << "-" << neg - pos << endl;
  return 0;
}