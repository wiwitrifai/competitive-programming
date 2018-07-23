#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int p[N];

vector<int> node[N];
vector<int> fact[N], g[N];

int main() {
  for (int i = 1; i < N; ++i) {
    for (int j = i; j < N; j += i)
      fact[j].push_back(i);
  }
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    for (int d : fact[a[i]])
      node[d].push_back(i);
  }
  for (int i = 0; i < n; ++i) {
    
  }
  return 0;
}