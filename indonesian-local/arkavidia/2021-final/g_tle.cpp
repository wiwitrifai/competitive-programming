#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char s[N];

void solve() {
  int n;
  scanf("%d", &n);
  scanf("%s", s);
  int cycle = n * 2 - 1;
  int len = cycle * 10;
  vector<int> rank(len);
  for (int i = 0; i < cycle; ++i) {
    int j = i >= n ? i - n : i;
    rank[i] = s[j] - '0';
  }
  for (int i = cycle; i < len; ++i) {
    rank[i] = rank[i - cycle] + 1;
    if (rank[i] >= 10)
      rank[i] = 0;
  }
  vector<int> tmp(len+1, 0), tmp2(len, 0);
  auto counting_sort = [&](vector<int> & id, int gap) {
    fill(tmp.begin(), tmp.end(), 0);
    for (int i : id) {
      int r = i + gap >= len ? 0 : rank[i + gap]+1;
      ++tmp[r];
    }
    for (int i = 0, sum = 0; i <= len; ++i) {
      int cur = sum;
      sum += tmp[i];
      tmp[i] = cur;
    }
    for (int i : id) {
      int r = i + gap >= len ? 0 : rank[i + gap]+1;
      tmp2[tmp[r]++] = i;
    }
    id.swap(tmp2);
  };
  vector<int> id(rank.size());
  iota(id.begin(), id.end(), 0);
  for (int gap = 1; gap < n; gap <<= 1) {
    auto cmp = [&](int l, int r) {
      if (rank[l] != rank[r])
        return rank[l] < rank[r];
      if (max(l, r) + gap >= len)
        return l > r;
      return rank[l + gap] < rank[r + gap];
    };
    counting_sort(id, gap);
    counting_sort(id, 0);
    for (int i = 1; i < len; ++i) {
      tmp[i] = tmp[i-1] + cmp(id[i-1], id[i]);
    }
    for (int i = 0; i < len; ++i) {
      rank[id[i]] = tmp[i];
    }
  }
  int shift = 0, pos = 0, best = rank.size();
  for (int i = 0; i <= 9; ++i) {
    for (int j = 0; j < n; ++j) {
      int cur = i * cycle + j;
      if (rank[cur] < best) {
        shift = i;
        pos = j;
        best = rank[cur];
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    int cur = i + pos;
    if (cur >= n)
      cur -= n;
    int now = s[cur] - '0';
    int ans = now + shift;
    if (ans >= 10)
      ans -= 10;
    printf("%d", ans);
  }
  printf("\n");
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
