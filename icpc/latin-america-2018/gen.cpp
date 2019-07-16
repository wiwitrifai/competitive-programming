#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int a[N];

int main() {
  srand(time(0));
  int n = 4e5;
  for (int i = 0; i < n; ++i)
    a[i] = (rand() % 300) + 1;
  vector<int> vs;
  int sum = 0;
  while (sum < n) {
    int s = (rand() % min(n-sum, 100000)) + 1;
    s = min(s, n-sum);
    sum += s;
    vs.push_back(s);
  }
  random_shuffle(vs.begin(), vs.end());
  printf("%d\n", (int)vs.size());
  int i = 0;
  for (int s : vs) {
    printf("%d", s);
    while (s--) {
      printf(" %d", a[i++]);
    }
    printf("\n");
  }
  return 0;
}