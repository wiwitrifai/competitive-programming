#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int cnt[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    cnt[a]++;
  }
  for (int i = 0; i < N; ++i) {
    if (cnt[i] & 1) {
      puts("Conan");
      return 0;
    }
  }
  puts("Agasa");
  return 0;
}