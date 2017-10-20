#include <bits/stdc++.h>

using namespace std;

const int N = 2e4 + 5;

vector<pair<int, int> > v[N];
vector<int> divs[N];

int main() {
  for (int i = 2; i < N; i++) {
    for (int j = i + i; j < N; j += i) {
      divs[j].push_back(i);
    }
  }
  for (int i = -150; i <= 150; i++) {
    for (int j = -150; j <= 150; j++) {
      int cur = i * i + j * j;
      if (cur < N) {
        v[cur].emplace_back(i, j);
      }
    }
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int p, q;
    scanf("%d %d", &p, &q);
    int sum = p * p + q * q;
    bool found = 0;
    for (auto i : divs[sum]) {
      if (i * i <= sum) {
        for (auto it : v[i]) {
          int m = it.first; 
          int n = it.second;
          int cur = m * m + n * n;
          if ((m*p + n*q) % cur == 0 && (m*q-n*p) % cur == 0) {
            found = 1;
            break;
          }
        }
      }
    }
    puts(found? "C" : "P");
  }

  return 0;
}