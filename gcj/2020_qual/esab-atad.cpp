#include <bits/stdc++.h>

using namespace std;

int ask(int p) {
  printf("%d\n", p+1);
  fflush(stdout);
  string res;
  cin >> res;
  if (res == "N")
    exit(0);
  stringstream ss(res);
  return res[0] - '0';
}

void answer(string ans) {
  cout << ans << endl;
  cout << flush;
  string res;
  cin >> res;
  if (res == "N")
    exit(0);
}

int n;

void solve() {
  string ans(n, '0');
  vector<int> res(n, 0);
  for (int i = 0, j = n-1; i < j;) {
    for (int k = 0; k < 5; ++k) {
      ans[i] = '0' + (res[i] = ask(i));
      ++i;
      ans[j] = '0' + (res[j] = ask(j));
      --j;
    }
  }
  int g = n / 10;
  vector<int> same(g, -1), diff(g, -1);
  for (int i = 0; i < n/2; ++i) {
    if (ans[i] == ans[n-1-i])
      same[i/5] = i;
    else
      diff[i/5] = i;
  }
  int pivot = -1;
  for (int i = 0; i < g; ++i) {
    if (same[i] != -1 && diff[i] != -1) {
      pivot = i;
    }
  }
  auto invertable = [&](int p) {
    if (same[p] == -1) {
      return res[diff[p]] != ans[diff[p]] - '0';
    }
    else {
      return res[same[p]] != ans[same[p]] - '0';
    }
  };
  auto swapable = [&](int p) {
    if (same[p] == -1 || diff[p] == -1)
      return false;
    return invertable(p) ? res[diff[p]] == ans[diff[p]] - '0' : res[diff[p]] != ans[diff[p]] - '0';
  };
  auto apply_invert = [&](int p) {
    for (int k = 0; k < 5; ++k) {
      int l = p * 5 + k, r = n-1-l;
      ans[l] = ('1' - ans[l]) + '0';
      ans[r] = ('1' - ans[r]) + '0';
      res[l] ^= 1;
      res[r] ^= 1;
    }
  };

  auto apply_swap = [&](int p) {
    for (int k = 0; k < 5; ++k) {
      int l = p * 5 + k, r = n-1-l;
      swap(ans[l], ans[r]);
      swap(res[l], res[r]);
    }
  };

  vector<int> vdiff, vsame;
  for (int i = 0; i < g; ++i) {
    if (diff[i] == -1)
      vsame.push_back(i);
    if (same[i] == -1)
      vdiff.push_back(i);
  }
  if ((int)vsame.size() == g)
    pivot = vsame.back();
  if ((int)vdiff.size() == g)
    pivot = vdiff.back();

  if (pivot != -1) {
    for (int i = 0, j = 0; i < g; ++i) {
      if (i == pivot) continue;
      if (j % 5 == 0) {
        int x = same[pivot], y = diff[pivot];
        if (x == -1)
          x = y;
        if (y == -1)
          y = x;
        res[x] = ask(x);
        res[y] = ask(y);
        j = (j + 1) % 5;
      }
      int u = same[i], v = diff[i];
      if (u == -1)
        u = v;
      if (v == -1)
        v = u;
      res[u] = ask(u);
      res[v] = ask(v);
      if (invertable(pivot) != invertable(i)) {
        apply_invert(i);
      }
      if (swapable(pivot) != swapable(i)) {
        apply_swap(i);
      }
      j = (j + 1) % 5;
    }
    bool swp = swapable(pivot), inv = invertable(pivot);
    for (int i = 0; i < n/2; ++i) {
      int r = n-1-i;
      if (swp) {
        swap(ans[i], ans[r]);
      }
      if (inv) {
        ans[i] = ('1' - ans[i]) + '0';
        ans[r] = ('1' - ans[r]) + '0';
      }
    }
    answer(ans);
  }
  else {
    int pdiff = vdiff.back();
    vdiff.pop_back();
    int psame = vsame.back();
    vsame.pop_back();
    while (vdiff.size() >= 9) {
      res[diff[pdiff]] = ask(diff[pdiff]);
      for (int i = 0; i < 9; ++i) {
        int now = vdiff.back();
        vdiff.pop_back();
        res[diff[now]] = ask(diff[now]);
        if (invertable(pdiff) != invertable(now)) {
          apply_invert(now);
        }
      }
    }
    while (vsame.size() >= 9) {
      res[same[psame]] = ask(same[psame]);
      for (int i = 0; i < 9; ++i) {
        int now = vsame.back();
        vsame.pop_back();
        res[same[now]] = ask(same[now]);
        if (invertable(psame) != invertable(now)) {
          apply_invert(now);
        }
      }
    }
    while (!vsame.empty() || !vdiff.empty()) {
      res[diff[pdiff]] = ask(diff[pdiff]);
      res[same[psame]] = ask(same[psame]);
      for (int i = 0; i < 8; ++i) {
        if (!vsame.empty()) {
          int now = vsame.back();
          vsame.pop_back();
          res[same[now]] = ask(same[now]);
          if (invertable(now) != invertable(psame)) {
            apply_invert(now);
          }
        }
        else if (!vdiff.empty()) {
          int now = vdiff.back();
          vdiff.pop_back();
          res[diff[now]] = ask(diff[now]);
          if (invertable(now) != invertable(pdiff)) {
            apply_invert(now);
          }
        }
        else
          break;
      }
    }
    int inv = invertable(psame), swp = invertable(pdiff);
    if (inv)
      swp = !swp;
    for (int i = 0; i < n/2; ++i) {
      int r = n-1-i;
      if (swp) {
        swap(ans[i], ans[r]);
      }
      if (inv) {
        ans[i] = ('1' - ans[i]) + '0';
        ans[r] = ('1' - ans[r]) + '0';
      }
    }
    answer(ans);
  }
}

int main() {
#ifdef LOCAL
  time_t starttime = clock();
#endif
  int tt;
  scanf("%d %d", &tt, &n);
  for (int tc = 1; tc <= tt; tc++) {
    // printf("Case #%d: ", tc);
    solve();
#ifdef LOCAL
    cerr << "~ TC#" << tc << " done! execution time: " <<
      (double)(clock()-starttime) / CLOCKS_PER_SEC << " s" << endl;
#endif
  }
  return 0;
}
