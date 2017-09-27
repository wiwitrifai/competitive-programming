#include <bits/stdc++.h>

using namespace std;

const int N = 100;
int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    a[i] = i+1;
  int ma = 0;
  do {
    int now = 0;
    for (int i = 0; i+1 < n; i++)
      now += abs(a[i+1] - a[i]);
    ma = max(ma, now);
  } while (next_permutation(a, a+n));
  sort(a, a+n);
  do {
    int now = 0;
    for (int i = 0; i+1 < n; i++)
      now += abs(a[i+1] - a[i]);
    if (now == ma) {
      for (int i = 0; i < n; i++)
        cerr << a[i] << " ";
      cerr << endl;
    }
  } while (next_permutation(a, a+n));
  return 0;
}