#include <bits/stdc++.h>

using namespace std;

char buffer[1024];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<int> secret;


vector<int> ask(vector<vector<int>> & s) {
#ifdef LOCAL
  vector<int> result;
  for (auto & p : s) {
    bool ok = false;
    for (int x : p) {
      for (int y : secret) {
        if (x == y) {
          ok = true;
        }
      }
      if (ok) {
        break;
      }
    }
    result.push_back(ok);
  }
  return result;
#endif
  printf("? %d\n", (int)s.size());
  for (auto & p : s) {
    printf("%d", (int)p.size());
    sort(p.begin(), p.end());
    for (int x : p) {
      printf(" %d", x);
    }
    printf("\n");
  }
  fflush(stdout);
  vector<int> ret;
  for (int i = 0; i < (int)s.size(); ++i) {
    scanf("%s", buffer);
    ret.push_back(buffer[0] == 'Y');
  }
  return ret;
}

void answer(vector<int> s) {
  sort(s.begin(), s.end());
#ifdef LOCAL
  cerr << " Ans: ";
  for (int x : s) {
    cerr << x << " ";
  }
  cerr << endl;

  cerr << " Correct: ";
  for (int x : secret) {
    cerr << x << " ";
  }
  cerr << endl;
  sort(secret.begin(), secret.end());
  assert(s == secret);
  exit(0);
#endif
  printf("!");
  for (int x : s) {
    printf(" %d", x);
  }
  printf("\n");
  fflush(stdout);
  exit(0);
}

void subtask1(int n) {
  int len = 31 - __builtin_clz(n);
  vector<vector<int>> a;
  for (int bit = 0; bit < len; ++bit) {
    vector<int> s;
    for (int i = 0; i < n; ++i) {
      if (i & (1 << bit)) {
        s.push_back(i+1);
      }
    }
    a.push_back(s);
  }
  vector<int> res = ask(a);
  int pos = 0;
  for (int i = 0; i < len; ++i) {
    if (res[i])
      pos |= 1 << i;
  }
  answer({pos + 1});
}

vector<int> rev;
vector<int> active;
vector<int> candidate;

void check() {
  int cnt = 0;
  for (int x : active)
    cnt += x;
  if (cnt == 2) {
    vector<int> ans;
    for (int i = 0; i < (int)candidate.size(); ++i) {
      if (active[i]) {
        ans.push_back(candidate[i]);
      }
    }
    answer(ans);
  }
}

void upd(vector<int>& res, vector<vector<int>>& a) {
  for (int i = 0; i < (int)res.size(); ++i) {
    if (res[i] == 0) {
      for (int x : a[i]) {
        active[rev[x]] = 0;
#ifdef LOCAL
        for (int y : secret) {
          assert(x != y);
        }
#endif
      }
    }
  }
}

void subtask2(int n) {
  int len = 31 - __builtin_clz(n);
  candidate.resize(n);
  active.assign(n, 1);
  rev.assign(n+1, -1);
  iota(candidate.begin(), candidate.end(), 1);
  shuffle(candidate.begin(), candidate.end(), rng);
  for (int i = 0; i < n; ++i)
    rev[candidate[i]] = i;
#ifdef LOCAL
  for (int x : secret) {
    for (int i = 0; i < n; ++i) {
      if (candidate[i] == x)
        cerr << i << " secret ";
    }
  }
  cerr << endl;
#endif
  vector<vector<int>> a;
  for (int bit = 0; bit < len; ++bit) {
    vector<int> s;
    for (int i = 0; i < n; ++i) {
      if (!active[i]) {
        s.push_back(candidate[i]);
        continue;
      }
      if (i & (1 << bit)) {
        s.push_back(candidate[i]);
      }
    }
    a.push_back(s);
  }
  vector<int> res_or = ask(a);
  upd(res_or, a);
  check();

  vector<vector<int>> b;
  vector<int> pos;
  for (int bit = 0; bit < len; ++bit) {
    if (res_or[bit] == 0) continue;
    pos.push_back(bit);
    vector<int> s;
    for (int i = 0; i < n; ++i) {
      if (!active[i]) {
        s.push_back(candidate[i]);
        continue;
      }
      if ((i & (1 << bit)) == 0) {
        s.push_back(candidate[i]);
      }
    }
    b.push_back(s);
  }
  vector<int> res_and = ask(b);
  upd(res_and, b);
  check();

  vector<vector<int>> c;
  int last = -1;
  vector<int> pos_xor;
  for (int i = 0; i < (int)res_and.size(); ++i) {
    if (res_and[i] == 1) {
      vector<int> s;
      int bit = pos[i];
      if (last == -1) {
        last = bit;
      } else {
        for (int j = 0; j < n; ++j) {
          if (!active[j]) {
            s.push_back(candidate[j]);
            continue;
          }
          if ((j & (1 << last)) == 0) continue;
          if ((j & (1 << bit)) == 0) continue;
          s.push_back(candidate[j]);
        }
        c.push_back(s);
        pos_xor.push_back(bit);
      }
    }
  }
  vector<int> res_xor = ask(c);
  upd(res_xor, c);
  check();
  assert(last != -1);
  int ans1 = 0, ans2 = 0;
  for (int i = 0; i < (int)pos.size(); ++i) {
    int bit = pos[i];
    if (res_and[i] == 0) {
      ans1 |= 1 << bit;
      ans2 |= 1 << bit;
    }
  }
  ans1 |= 1 << last;
  for (int i = 0; i < (int)pos_xor.size(); ++i) {
    int bit = pos_xor[i];
    if (res_xor[i] == 1) {
      ans1 |= 1 << bit;
    }
    else {
      ans2 |= 1 << bit;
    }
  }
  answer({candidate[ans1], candidate[ans2]});
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
#ifdef LOCAL
  for (int i = 0; i < k; ++i) {
    while (true) {
      int x = uniform_int_distribution<int>(1, n)(rng);
      bool ok = true;
      for (int y : secret) {
        if (x == y) {
          ok = false;
          break;
        }
      }
      if (ok) {
        secret.push_back(x);
        break;
      }
    }
  }
#endif
  if (k == 1)
    subtask1(n);
  else if (k == 2)
    subtask2(n);
  return 0;
}
