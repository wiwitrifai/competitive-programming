#include <bits/stdc++.h>

using namespace std;

const int M = 2, N = 1024;
int mod[] = {int(1e9 + 7), int(1e9 + 9)};
int p[] = {29, 37};
long long pp[M][N];

struct hashh {
  long long x[M];
  hashh() {
    memset(x, 0, sizeof x);
  }
  hashh(vector<int> v) {
    sort(v.begin(), v.end());
    for (int i = 0; i < M; i++) {
      x[i] = 0;
      for (int z : v) {
        x[i] += pp[i][z];
        if (x[i] >= mod[i])
          x[i] -= mod[i];
      }
    }
  }
  hashh operator-(hashh ot) {
    hashh res;
    for (int i = 0; i < M; i++) {
      res.x[i] = (x[i] - ot.x[i]) % mod[i];
      if (res.x[i] < 0)
        res.x[i] += mod[i];
    } 
    return res;
  }
  bool operator<(const hashh& ot) const {
    for (int i = 0; i < M; i++) if (x[i] != ot.x[i])
      return x[i] < ot.x[i];
    return true;
  }
  bool operator==(const hashh& ot) const {
    for (int i = 0; i < M; i++) if (x[i] != ot.x[i])
      return false; 
    return true;
  }
};

vector<hashh> st[N]; 

int main() {
  for (int i = 0; i < M; i++) {
    pp[i][0] = 1;
    for (int j = 1; j < N; j++) {
      pp[i][j] = (pp[i][j-1] * p[i]) % mod[i];
    }
  }
  int n;
  scanf("%d", &n);
  vector<int> all;
  int tot_deg = 0;
  for (int i = 1; i <= n; i++) {
    all.push_back(i);
    int ot = n-1;
    while (ot > 0) {
      int k;
      scanf("%d:", &k);
      vector<int> ve;
      for (int j = 0; j < k; j++) {
        int z;
        scanf("%d%*c", &z);
        ve.push_back(z);
      }
      ot -= k;
      hashh hh(ve);
      st[i].push_back(hh);
      tot_deg++;
    }
  }
  if (tot_deg != 2 * (n-1)) {
    puts("-1");
    return 0;
  }
  hashh hall = hashh(all);
  vector<pair<int, int> > pairs;
  for (int i = 1; i <= n; i++) {
    for (hashh h : st[i]) {
      hashh inv = hall - h;
      for (int j = 1; j <= n; j++) {
        bool ok = 0;
        for (hashh hh : st[j])
          if (inv == hh)
            ok = 1;
        if (!ok) continue;
        int a = i, b = j;
        if (a > b)
          swap(a, b);
        pairs.push_back({a, b});
      }
    }
  }
  sort(pairs.begin(), pairs.end());
  if (pairs.size() != 2 * (n-1)) {
    puts("-1");
    return 0;
  }
  for (int i = 0; i < 2 * (n-1); i+= 2)
    if (pairs[i] != pairs[i+1]) {
      puts("-1");
      return 0;
    }
  printf("%d\n", n-1);
  for (int i = 0; i < pairs.size(); i+= 2)
    printf("%d %d\n", pairs[i].first, pairs[i].second);
  return 0;
}