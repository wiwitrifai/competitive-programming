// can you hack wifi? :p
#include <bits/stdc++.h>

using namespace std;

const int N = 5050;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
  }
  sort(a, a+n);
  multiset<int> ms;
  for (int i = 0; i < n; ++i) {
    ms.insert(a[i]);
    auto it = ms.lower_bound(a[i]);
    if (it != ms.begin()) {
      it--;
      ms.erase(it);
    }
  }
  printf("%d\n", ms.size());

  return 0;
}