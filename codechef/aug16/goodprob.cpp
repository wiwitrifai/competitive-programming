#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, LN = 17;
const int A = (1<<14) + 7;

int a[N], ma[LN][N];
stack < pair< int, int > > st[A][3];
int upd[A];
long long sum[A][3];

int get(int l, int r) {
  int len = r-l + 1;
  int ln = 31 - __builtin_clz(len);
  return max(ma[ln][l], ma[ln][r - (1<<ln) + 1]);
}

void update(int x, int id) {
  if (upd[x] >= id)
    return;
  int val = get(upd[x] + 1, id);
  for (int i = 0; i < 3; i++) {
    int cnt = 0;
    while (!st[x][i].empty()) {
      if (st[x][i].top().first <= val) {
        auto it = st[x][i].top();
        st[x][i].pop();
        sum[x][i] += 1LL * (val - it.first) * it.second;
        cnt += it.second;
      }
      else
        break;
    }
    if (cnt) {
      st[x][i].push({val, cnt});
    }
  }
  upd[x] = id;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
    ma[0][i] = a[i];
  }
  for (int i = 0; i + 1 < LN; i++) {
    for (int j = n - (1<<(i+1)); j >= 0; j--)
      ma[i+1][j] = max(ma[i][j], ma[i][j+(1<<i)]);
  }

  memset(upd, -1, sizeof upd);
  int m = 7, mm = 1<<m, mask = mm - 1;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    long long cur = 0;
    int bitl = a[i]>>m, bitr = a[i] & mask;
    for (int j = 0; j < mm; j++) {
      int now = (j << m) | bitr;
      update(now, i);
      if (bitl == j) {
        cur += sum[now][0] + sum[now][1] + sum[now][2];
        // cerr << now << " " << sum[now][0] << " " <<  sum[now][1]  << " " <<  sum[now][2] << endl;
      }
      else if ((bitl & j) == bitl) {
        cur += sum[now][0] + sum[now][1];
        // cerr << now << " " <<  sum[now][0] << " " << sum[now][1] << " " << -1 << endl;
      }
      else if ((bitl & j) == j) {
        cur += sum[now][1] + sum[now][2];
        // cerr << now << " " << -1 << " " <<  sum[now][1] << " " << sum[now][2] << endl;
      }
    }
    // cerr << i << " final " << cur << endl;
    ans += cur;
    bitl <<= m;
    for (int j = 0; j < mm; j++) if ((bitr & j) == j || (bitr & j) == bitr) {
      int now = bitl | j, id = 0;
      if (bitr == j)
        id = 1;
      else if((bitr & j) == bitr)
        id = 2;
      else
        id = 0;
      update(now, i);
      int cnt = 1;
      if (!st[now][id].empty()) {
        if (st[now][id].top().first == a[i]) {
          cnt += st[now][id].top().second;
          st[now][id].pop();
        }
        else
          assert(st[now][id].top().first > a[i]);
      }
      sum[now][id] += a[i];
      st[now][id].push({a[i], cnt});
    }
  }
  printf("%lld\n", ans);
  return 0;
}