#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

vector<int> id[N], satu, dua;

int a[N], b[N];

void solve1(vector<int> s) {
  if (s.size() <= 1) return;
  s.push_back(s[0]);
  for (int i = 0; i + 1 < s.size(); i++) {
    b[id[s[i]][0]] = s[i+1];
  }
}
void solve2(vector<int> d) {
  if (d.size() <= 1) return;
  d.push_back(d[0]);
  for (int i = 0; i + 1 < d.size(); i++) {
    b[id[d[i]][0]] = d[i+1];
    b[id[d[i]][1]] = d[i+1];
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    satu.clear();
    dua.clear();
    for (int i = 0; i < N; i++)
      id[i].clear();
    for (int i = 0; i < n; ++i)
      scanf("%d", a+i), id[a[i]].push_back(i), b[i] = a[i];
    for (int i = 0; i < N; ++i) {
      if (id[i].empty()) continue;
      if (id[i].size() == 1)
        satu.push_back(i);
      else
        dua.push_back(i);
    }
    if (satu.size() == 1 && dua.size() == 1) {
      for (int i = 0; i < 3; i++)
        b[i] = dua[0];
      b[id[dua[0]][0]] = satu[0];
    }
    else if (satu.size() == 1) {
      solve2(dua);
      if (!dua.empty())
        swap(b[id[satu[0]][0]], b[id[dua[0]][0]]);
    }
    else if (dua.size() == 1) {
      solve1(satu);
      for (int i = 0; i < min(2, (int)satu.size()); i++) {
        swap(b[id[dua[0]][i]], b[id[satu[i]][0]]);
      }
    }
    else {
      solve1(satu);
      solve2(dua);
    }
    int hamming = 0;
    for (int i = 0; i < n; i++)
      hamming += a[i] != b[i];
    printf("%d\n", hamming);
    for (int i = 0; i < n; i++)
      printf("%d%c", b[i], " \n"[i == n-1]);
  }
  return 0;
}