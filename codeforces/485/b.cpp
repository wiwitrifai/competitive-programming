#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int a[N];

int main() {
  srand(time(0));
  int n;
  int k;
  scanf("%d %d", &n, &k);
  cout << n << endl;
  for (int i = 0; i < n; ++i)
    a[i] = i+1;
  int banyak = 3 * n + k * (3 * n + 1);
  for (int i = 0; i < banyak; ++i) {
    int u = rand() % n, v = rand() % n;
    while (v == u) v = rand() % n;
    swap(a[u], a[v]);
  }
  for (int i = 0; i < n; ++i)
    cout << a[i] << " ";
  cout << endl;
  cerr << " done " << endl;
  return 0;
}