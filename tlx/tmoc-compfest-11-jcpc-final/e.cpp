#include <bits/stdc++.h>

using namespace std;

const int N = 2001;

long long sum[N][N];
int a[N][N];
int low[N], hig[N][N];
int up[N], down[N];
int downsize, upsize;

int main() {
  int n, m;
  long long k;
  scanf("%d %d %lld", &n, &m, &k);
  sum[0][0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", a[i]+j);
    }
  }
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      if (i + 1 <= n)
        sum[i+1][j] += sum[i][j];
      if (j + 1 <= m)
        sum[i][j+1] += sum[i][j];
      if (i+1 <= n && j+1 <= m)
        sum[i+1][j+1] += a[i][j] - sum[i][j];
    }
  }
  int ra = 0, ca = 0, rb = n-1, cb = m-1;
  long long mini = sum[n][m];
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i][j] > k) {
        if (mini > a[i][j]) {
          mini = a[i][j];
          ra = rb = i;
          ca = cb = j;
        }
      }
    }
  }
  if (mini <= 2 * k) {
    puts("2");
    printf("%d %d %d %d\n", ra + 1, ca + 1, rb + 1, cb + 1);
    return 0;
  }
  bool found = false;
  mini = sum[n][m] + 1;
  int tra = ra, tca = ca, trb = rb, tcb = cb;
  ra = ca = 0;
  rb = n-1;
  cb = m-1;
  auto compare = [&](int top, int lef, int bot, int rig) {
    if (top > bot || lef > rig || top < 0 || bot >= n || lef < 0 || rig >= m) return;
    ++bot, ++rig;
    long long cur = sum[bot][rig] - sum[bot][lef] - sum[top][rig] + sum[top][lef];
    if (cur > k && mini > cur) {
      mini = cur;
      ra = top;
      ca = lef;
      rb = bot-1;
      cb = rig-1;
      found = 1;
    }
  };
  fill(hig[n-1], hig[n-1]+m, n-1);
  for (int i = n-1; i >= 0; --i) {
    for (int j = 0; j < m; ++j) {
      if (i < n-1)
        hig[i][j] = hig[i+1][j];
      if (a[i][j] > k) {
        hig[i][j] = i-1;
      }
    }
  }
  auto process = [&](int i, int til) {
    int last = 0;
    int idown = 0, iup = 0;
    while (idown < downsize && iup < upsize) {
      compare(low[down[idown]], last, hig[i][up[iup]], til);
      last = min(down[idown], up[iup]) + 1;
      while (idown < downsize && down[idown] < last) ++idown;
      while (iup < upsize && up[iup] < last) ++iup;
    }
  };
  for (int i = 0; i < n; ++i) {
    downsize = 0, upsize = 0;
    for (int j = 0; j < m; ++j) {
      if (a[i][j] > k) {
        process(i, j-1);
        low[j] = i+1;
      }
      while (downsize > 0 && low[down[downsize-1]] <= low[j]) --downsize;
      down[downsize++] = j;
      while (upsize > 0 && hig[i][up[upsize-1]] >= hig[i][j]) --upsize;
      up[upsize++] = j;
    }
    process(i, m-1);
  }
  if (found) {
    for (int i = ra; i <= rb; ++i)
      for (int j = ca; j <= cb; ++j)
        assert(a[i][j] <= k);
    mini = sum[rb+1][cb+1] - sum[rb+1][ca] - sum[ra][cb+1] + sum[ra][ca];
    while (1) {
      bool done = 1;
      if (ra < rb) {
        long long cur = sum[rb][cb+1] - sum[rb][ca] - sum[ra][cb+1] + sum[ra][ca];
        if (cur > k) {
          mini = cur;
          --rb;
          done = 0;
        }
      }
      if (ra < rb) {
        long long cur = sum[rb+1][cb+1] - sum[rb+1][ca] - sum[ra+1][cb+1] + sum[ra+1][ca];
        if (cur > k) {
          mini = cur;
          ++ra;
          done = 0;
        }
      }
      if (ca < cb) {
        long long cur = sum[rb+1][cb] - sum[rb+1][ca] - sum[ra][cb] + sum[ra][ca];
        if (cur > k) {
          mini = cur;
          --cb;
          done = 0;
        }
      }
      if (ca < cb) {
        long long cur = sum[rb+1][cb+1] - sum[rb+1][ca+1] - sum[ra][cb+1] + sum[ra][ca+1];
        if (cur > k) {
          mini = cur;
          ++ca;
          done = 0;
        }
      }
      if (done)
        break;
    }
    // assert(mini > k && mini <= 2 * k);
  }
  else {
    ra = tra;
    rb = trb;
    ca = tca;
    cb = tcb;
    assert(ra == rb && ca == cb);
    mini = sum[rb+1][cb+1] - sum[rb+1][ca] - sum[ra][cb+1] + sum[ra][ca];
  }
  printf("%lld\n", ((mini + k - 1) / k));
  printf("%d %d %d %d\n", ra + 1, ca + 1, rb + 1, cb + 1);
  return 0;
}
