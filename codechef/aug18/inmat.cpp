#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

int A[N][N];
bool cand[N][N];
int n, k, v;

void done(int i, int j) {
  printf("2 %d %d\n", i, j);
  fflush(stdout);
  exit(0);
}

int ask(int i, int j) {
  if (A[i][j] != -1)
    return A[i][j];
  printf("1 %d %d\n", i, j);
  fflush(stdout);
  assert(k > 0);
  --k;
  scanf("%d", &A[i][j]);
  if (A[i][j] == v) {
    done(i, j);
  }
  return A[i][j];
}

bool inc_row(int i) {
  if (i < n)
    return ask(i, i) < ask(i, i+1);
  else
    return ask(n, 1) < ask(n, n);
}

bool inc_col(int j) {
  if (j > 1)
    return ask(j-1, j) < ask(j, j);
  else
    return ask(1, 1) < ask(n, 1);
}

int lo[N], hi[N], le[N], ri[N];

set<pair<int, int> > st;
void rem_up(int i, int j) {
  if (min(i, j) <= 0 || max(i, j) > n) return;
  if (!cand[i][j]) return;
  st.erase(make_pair(i, j));
  cand[i][j] = false;
  if (inc_row(i))
    rem_up(i, j+1), ri[i] = min(ri[i], j-1);
  else
    rem_up(i, j-1), le[i] = max(le[i], j+1);
  if (inc_col(j))
    rem_up(i+1, j), hi[j] = min(hi[j], i-1);
  else
    rem_up(i-1, j), lo[j] = max(lo[j], i+1);
}

void rem_down(int i, int j) {
  if (min(i, j) <= 0 || max(i, j) > n) return;
  if (!cand[i][j]) return;
  st.erase(make_pair(i, j));
  cand[i][j] = false;
  if (inc_row(i))
    rem_down(i, j-1), le[i] = max(le[i], j+1);
  else
    rem_down(i, j+1), ri[i] = min(ri[i], j-1);
  if (inc_col(j))
    rem_down(i-1, j), lo[j] = max(lo[j], i+1);
  else
    rem_down(i+1, j), hi[j] = min(hi[j], i-1);
}

int main() {
  memset(A, -1, sizeof A);
  scanf("%d %d %d", &n, &k, &v);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      st.insert(make_pair(i, j));
  for (int i = 1; i <= n; ++i) {
    lo[i] = le[i] = 1;
    hi[i] = ri[i] = n;
  }
  memset(cand, true, sizeof cand);
  vector<pair<int, int> > border;
  border.push_back(make_pair(n, 1));
  for (int i = 1; i <= n; ++i) {
    border.push_back(make_pair(i, i));
    if (i < n)
      border.push_back(make_pair(i, i+1));
  }
  for (auto it : border) {
    if (ask(it.first, it.second) > v)
      rem_up(it.first, it.second);
    else
      rem_down(it.first, it.second);
  }
  bool resetup = true, resetdown = true;
  while (!st.empty()) {
    pair<int, int> pil;
    int row = -1, col = -1;
    for (int i = 1; i <= n; ++i) {
      if (row == -1 || (ri[row] - le[row] < ri[i] - le[i]))
        row = i;
      if (col == -1 || (hi[col] - lo[col] < hi[i] - lo[i]))
        col = i;
    }
    if (ri[row] - le[row] > hi[col] - lo[col]) {
      pil.first = row;
      pil.second = (le[row] + ri[row]) / 2;
    }
    else {
      pil.first = (lo[col] + hi[col]) / 2;
      pil.second = col;
    }
    if (ask(pil.first, pil.second) > v)
      rem_up(pil.first, pil.second), resetup = 1;
    else
      rem_down(pil.first, pil.second), resetdown = 1;
  }
  done(-1, -1);
  return 0;
}