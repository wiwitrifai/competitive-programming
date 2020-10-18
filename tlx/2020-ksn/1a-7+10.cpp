// Subtask 7 and 10

#include <bits/stdc++.h>

using namespace std;

vector<int> xa, xb, ya, yb;

vector<pair<int, int>> find_factor(int x) {
  vector<pair<int, int>> ret;
  for (int i = 1; i * i <= x; ++i) {
    int u = i, v = x / i;
    ret.emplace_back(u, v);
    if (u != v)
      ret.emplace_back(v, u);
  }
  sort(ret.begin(), ret.end());
  return ret;
}

void upd(int id, int a, int b, int c, int d) {
  xa[id] = a;
  xb[id] = b;
  ya[id] = c;
  yb[id] = d;
}

int main() {
  int n, k, m;
  scanf("%d %d %d", &n, &m, &k);
  int score = k;
  vector<int> a(k);
  xa.assign(k, -1);
  xb.assign(k, -1);
  ya.assign(k, -1);
  yb.assign(k, -1);
  vector<int> odd, even;
  vector<pair<int, int>> pa;
  for (int i = 0; i < k; ++i) {
    scanf("%d", &a[i]);
    if (a[i] & 1)
      odd.push_back(i);
    else
      even.push_back(i);
    pa.emplace_back(a[i], i);
  }
  sort(pa.begin(), pa.end());
  int sum = 0, tot = n * m;
  // int limit = tot/10;
  int limit = 0;
  vector<int> rem;
  while (sum < limit && !pa.empty()) {
    sum += pa.back().first;
    rem.push_back(pa.back().second);
    pa.pop_back();
  }
  reverse(pa.begin(), pa.end());
  vector<int> h(n, 0);
  for (auto it : pa) {
    int luas = it.first, id = it.second;
    int pos = -1, hig = -1;
    for (int i = 0; i < n; ++i) {
      if (h[i] + luas <= m) {
        if (hig < h[i]) {
          pos = i;
          hig = h[i];
        }
      }
    }
    if (pos == -1) {
      rem.push_back(id);
    } else {
      upd(id, pos, pos+1, h[pos], h[pos] + luas);
      score += 2;
      h[pos] += luas;
    }
  }
  for (int id : rem) {
    for (int i = 0; i < n; ++i) {
      if (h[i] < m) {
        upd(id, i, i+1, h[i], h[i] + 1);
        h[i] += 1;
        break;
      }
    }
  }
  for (int i = 0; i < k; ++i) {
    if (xa[i] > xb[i]) {
      swap(xa[i], xb[i]);
    }
    if (ya[i] > yb[i]) {
      swap(ya[i], yb[i]);
    }
    printf("%d %d %d %d\n", xa[i], xb[i], ya[i], yb[i]);
  }
  if (score == k * 3)
    cerr << 10 << endl;
  else
    cerr << ((double)score/k) * (double) score / k << endl;
  return 0;
}
