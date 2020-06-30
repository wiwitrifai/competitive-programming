#include <bits/stdc++.h>

using namespace std;

map<pair<int, int>, int> mp;
vector<int> res, low, b;

int ask(int l, int r) {
  if (l == r)
    return -1;
  if (l > r)
    swap(l, r);
  if ((res[l] | res[r]) == (low[l] | low[r]))
    return res[l] | res[r];
  auto it = mp.find(make_pair(l, r));
  if (it != mp.end())
    return it->second;
  printf("? %d %d\n", l, r);
  fflush(stdout);

  int x;
#ifdef LOCAL
  x = b[l-1] | b[r-1];
#else
  scanf("%d", &x);
#endif
  mp[make_pair(l, r)] = x;
  res[l] &= x;
  res[r] &= x;

  for (auto p : mp) {
    low[p.first.first] |= p.second^res[p.first.second];
    low[p.first.second] |= p.second^res[p.first.first];
  }
  return x;
}
int n;

void answer() {
  printf("!");
  for (int i = 1; i <= n; ++i) {
    printf(" %d", res[i]);
  }
  printf("\n");
  fflush(stdout);
#ifdef LOCAL
  for (int i = 0; i < n; ++i)
    assert(res[i+1] == b[i]);
  cerr << " queries : " << mp.size() << endl;
#endif
  exit(0);
}

int main() {
  scanf("%d", &n);
#ifdef LOCAL
  srand(time(0));
  b.resize(n);
  iota(b.begin(), b.end(), 0);
  random_shuffle(b.begin(), b.end());
#endif
  int full = (1 << 18)-1;
  res.assign(n+1, full);
  low.assign(n+1, 0);

  int cnt = 4269 - n * 2;
  srand(time(0));
  int p = -1, q = -1;
  while (cnt-- > 0) {
    int x = (rand() % n) + 1;
    int y = (rand() % n) + 1;
    while (x == y) {
      y = (rand() % n) + 1;
    }
    ask(x, y);
    bool found = false;
    for (int i = 1; i <= n; ++i) {
      for (int j = i+1; j <= n; ++j) {
        if (res[i] & res[j]) continue;
        p = i;
        q = j;
        found = true;
      }
    }
    if (found)
      break;
  }

  if (p != -1 && q != -1) {
    for (int i = 1; i <= n; ++i) {
      ask(i, p);
      ask(i, q);
    }
    answer();
  }

  int zero = -1;
  while (true) {
    vector<int> cand;
    for (int i = 1; i <= n; ++i) {
      if (low[i]) continue;
      cand.emplace_back(i);
    }

    if (cand.size() == 2) {
      for (int i = 1; i <= n; ++i) {
        if ((res[i] & res[cand[0]]) == 0) {
          ask(i, cand[0]);
          break;
        }
        if ((res[i] & res[cand[1]]) == 0) {
          ask(i, cand[1]);
        }
      }
    } else if (cand.size() == 1) {
      zero = cand[0];
      break;
    }

    sort(cand.begin(), cand.end(), [](int l, int r) {
      return __builtin_popcount(res[l]) < __builtin_popcount(res[r]);
    });

    for (int x : cand) {
      ask(x, cand[0]);
    }

    for (int x : cand) {
      if (res[x] == 0) {
        zero = x;
        break;
      }
    }
    if (zero != -1)
      break;
  }
  for (int i = 1; i <= n; ++i) {
    ask(zero, i);
  }
  answer();
  return 0;
}
