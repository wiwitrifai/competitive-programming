#include <bits/stdc++.h>

using namespace std;

const int N = 6100;

vector<string> s;
long long ans;
int n, m;

bool ada[N][N], a[N][N], b[N][N], c[N][N];
int d[N][N], f[N][N];
int bit[N];

void add(int i, int val) {
  for (; i < N; i |= i + 1) {
    bit[i] += val;
  }
}

int find(int i) {
  int ret = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1) ret += bit[i];
  return ret;
}

int find(int l, int r) {
  if (l > r) return 0;
  return find(r) - find(l - 1);
}

bool valid(int i, int j) {
  return 0 <= i && i < n && 0 <= j && j < m;
}

void solve() {
  memset(ada, 0, sizeof(ada));
  memset(a, 0, sizeof(a));
  memset(b, 0, sizeof(a));
  memset(c, 0, sizeof(a));
  memset(d, 0, sizeof(d));
  memset(f, 0, sizeof(f));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (j * 2 < s[i * 2].size() && s[i * 2][j * 2] == 'x') {
        ada[i][j] = 1;
      }
    }
  }
  //puts("ada");

  for (int i = 0; i < s.size(); i++) {
    for (int j = 0; j < s[i].size(); j++) {
      if (s[i][j] == '-') {
        b[i/2][j/2] = 1;
      } else if (s[i][j] == '/') {
        a[i/2 + 1][j/2] = 1;
      } else if (s[i][j] == '\\') {
        c[i/2][j/2] = 1;
      }
    }
  }

  for (int i = n - 2; i >= 0; i--) {
    int pi = i;
    int pj = m - 1;
    if (!ada[pi][pj]) continue;
    int now = 0;
    while (valid(pi, pj)) {
      d[pi][pj] = now;
      pi--;
      pj--;
      if (valid(pi, pj)) {
        if (c[pi][pj]) {
          now++;
        } else {
          now = 0;
        }
      }
    }
  }

  for (int j = 0; j < m; j++) {
    int pi = n - 1;
    int pj = j;
    if (!ada[pi][pj]) continue;
    int now = 0;
    while (valid(pi, pj)) {
      d[pi][pj] = now;
      pi--;
      pj--;
      if (valid(pi, pj)) {
        if (c[pi][pj]) {
          now++;
        } else {
          now = 0;
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    int now = 0;
    for (int j = m - 1; j >= 0; j--) {
      if (!ada[i][j]) continue;
      if (b[i][j]) {
        now++;
      } else {
        now = 0;
      }
      f[i][j] = now;
    }
  }

  vector<pair<int, int>> st;
  for (int i = 0; i < n; i++) st.emplace_back(i, 0);
  for (int j = 1; j < m; j++) st.emplace_back(n - 1, j);
  for (auto it : st) {
    int sti = it.first;
    int stj = it.second;
    if (!ada[sti][stj]) continue;
    for (int pi = sti, pj = stj; valid(pi, pj); pi--, pj++) {
      int qi = pi, qj = pj;
      while (valid(qi, qj) && a[qi][qj]) qi--, qj++;
      //printf("pi pj %d %d qi qj %d %d\n", pi, pj, qi, qj);
      priority_queue<pair<int, int>> pq ;
      for (int p = pi; p > qi; p--) {
        int lvl = (f[p][pj + pi - p] + 1 + pi - p);
        pq.emplace(-lvl, p);
        add(p, 1);
      }
      for (int p = pi - 1; p >= qi; p--) {
        int lvl = pi - p;
        while (!pq.empty() && pq.top().first == -lvl) {
          auto it = pq.top();
          add(it.second, -1);
          pq.pop();
        }
        int niki = min(pi - p, d[p][pj + lvl]);
        //printf("pi pj %d %d qi qj %d %d: wow %d\n", pi, pj, qi, qj, niki);
        ans += find(p + 1, p + niki);
      }
      while (!pq.empty()) {
        auto it = pq.top().second;
        add(it, -1);
        pq.pop();
      }

      pi = qi, pj = qj;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m; cin.ignore();
  for (int i = 0; i < 2 * n - 1; i++) {
    string buf;
    getline(cin, buf);
    s.push_back(buf);
  }
  //puts("input done");
  solve();
  //puts("--- REVERSE ----");
  reverse(s.begin(), s.end());
  for (int i = 0; i < s.size(); i++) {
    for (int j = 0; j < s[i].size(); j++) {
      if (s[i][j] == '/') {
        s[i][j] = '\\';
      } else if (s[i][j] == '\\') {
        s[i][j] = '/';
      }
    }
  }
  solve();
  cout << ans << endl;
  return 0;
}
