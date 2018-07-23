#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, M = 2, MAGIC = 155;

const int mod[] = {int(1e9 + 7), int(1e9 + 9)};
const int p[] = {37, 29};

long long pp[N][M];
struct hashh {
  int x[M], len;
  hashh() : len(0) { memset(x, 0, sizeof x); }
  hashh(int v) : len(1) {
    for (int i = 0; i < M; ++i) x[i] = v;
  }
  hashh operator+(hashh h) {
    hashh ret;
    ret.len = len + h.len;
    for (int i = 0; i < M; ++i) {
      ret.x[i] = (1LL * x[i] * pp[h.len][i] + h.x[i]) % mod[i];
    }
    return ret;
  }
  hashh operator-(hashh h) {
    hashh ret;
    ret.len = max(len, h.len);
    for (int i = 0; i < M; ++i) {
      ret.x[i] = (x[i] - h.x[i]) % mod[i];
      if (ret.x[i] < 0) ret.x[i] += mod[i];
    }
    return ret;
  }
  hashh operator*(int v) {
    hashh ret;
    ret.len = len + v;
    for (int i = 0; i < M; ++i) {
      ret.x[i] = (1LL * x[i] * pp[v][i]) % mod[i];
    }
    return ret;
  }
  bool operator==(hashh h) const {
    for (int i = 0; i < M; ++i)
      if (x[i] != h.x[i]) return false;
    return true;
  }
  bool operator <(hashh h) const {
    for (int i = 0; i < M; ++i) {
      if (x[i] != h.x[i])
        return x[i] < h.x[i];
    }
    return false;
  }
};

hashh h[N];
char s[N], t[N];
vector<int> que[N];
int ans[N];

int main() {
  for (int i = 0; i < M; ++i)
    pp[0][i] = 1;
  for (int i = 0; i + 1 < N; ++i) {
    for (int j = 0; j < M; ++j) {
      pp[i+1][j] = (1LL * pp[i][j] * p[j]) % mod[j];
    }
  }
  int n, m;
  scanf("%d %d", &n, &m);
  scanf("%s", s);
  for (int i = 0; i < n; ++i) {
    s[i] -= 'a'-1;
  } 
  for (int i = 0; i < m; ++i) {
    scanf("%s", t);
    int len = strlen(t);
    h[i].len = 0;
    for (int j = 0; j < len; ++j) {
      t[j] -= 'a'-1;
      h[i] = h[i] + hashh(t[j]);
    }
    if (len < MAGIC) {
      que[len].push_back(i);
    }
    else {
      hashh now;
      ans[i] = 0;
      for (int j = 0; j < len; ++j)
        now = now + hashh(s[j]);
      for (int j = len; j <= n;) {
        if (now == h[i]) {
          ++ans[i];
          now = hashh();
          now.len = 0;
          if (j + len <= n) {
            for (int k = 0; k < len; ++k) {
              now = now + hashh(s[j+k]);
            }
          }
          j += len;
          continue;
        }
        now = (now + hashh(s[j])) - (hashh(s[j-len]) * len);
        now.len = len;
        ++j;
      }
    }
  }
  for (int len = 1; len < MAGIC; ++len) {
    if (que[len].empty()) continue;
    hashh now;
    for (int i = 0; i < len; ++i)
      now = now + hashh(s[i]);
    vector<pair<hashh, int> > vh;
    for (int i = len; i <= n; ++i) {
      vh.emplace_back(now, i);
      if (i == n) break;
      now = (now + hashh(s[i])) - (hashh(s[i-len]) * (len));
      now.len = len;
    }
    sort(vh.begin(), vh.end());
    sort(que[len].begin(), que[len].end(), [&](int le, int ri) {
      return h[le] < h[ri];
    });
    for (int i = 0, j = 0; i < vh.size();) {
      hashh now = vh[i].first;
      int last = vh[i].second;
      int cnt = 1;
      ++i;
      while (i < vh.size() && vh[i].first == now) {
        if (last + len <= vh[i].second) {
          last = vh[i].second;
          ++cnt;
        }
        ++i;
      }
      while (j < que[len].size() && h[que[len][j]] < now) ans[que[len][j]] = 0, ++j;
      while (j < que[len].size() && h[que[len][j]] == now) ans[que[len][j]] = cnt, ++j;
    }
  }
  for (int i = 0; i < m; ++i)
    printf("%d\n", ans[i]);
  return 0;
}
