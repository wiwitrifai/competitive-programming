#include <bits/stdc++.h>

using namespace std;

const int N = 1024;


int a[N][N];
int l[N], r[N], ma[N];
int n, m;
int id[N];
int inv[N];
long double w[N];
int pivot;

bool cmp(int le, int ri) {
  if (a[le][pivot] == a[ri][pivot])
    return le < ri;
  return a[le][pivot] < a[ri][pivot];
}

int bit[N];
int get(int x) {
  int res = 0;
  for (; x <= n; x += x&-x)
    res += bit[x];
  return res;
}
void upd(int x, int v = 1) {
  for (; x; x -= x&-x)
    bit[x] += v;
}

long double calc(long long mid) {
  long long tot = 0;
  long long sum = 0;
  for (int i = 0; i < m; ++i) {
    long long cur = min(r[i], max((int)(mid * w[i] + 0.5), l[i]));
    tot += cur;
    sum += cur * inv[i];
  }
  return (long double)sum/tot;
}

int countInversion() {
  memset(bit, 0, sizeof bit);
  int res = 0;
  for (int i = 0; i < n; ++i) {
    res += get(id[i]+1);
    upd(id[i]+1);
  }
  return res;
}
long long score[N];
bool cmp2(int le, int ri) {
  if (score[le] == score[ri])
    return le < ri;
  return score[le] < score[ri];
}
int calc2(long long mid) {
  for (int i = 0; i < m; ++i) {
    ma[i] = min(r[i], max((int)(mid * w[i] + 0.5), l[i]));
  }
  for (int i = 0; i < n; ++i) {
    score[i] = 0;
    for (int j = 0; j < m; ++j) {
      score[i] += 1LL * a[i][j] * ma[j];
    }
  }
  sort(id, id+n, cmp2);
  return countInversion();
}


int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
      scanf("%d %d", l+i, r+i);
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        scanf("%d", a[i]+j);
      }
    }
    for (int i = 0; i <  n; ++i)
      id[i] = i;
    long long tot = 0;
    for (int i = 0; i < m; ++i) {
      pivot = i;
      sort(id, id+n, cmp);
      inv[i] = countInversion();
      tot += n * (n-1) / 2 - inv[i];
    }
    for (int i = 0; i < m; ++i)
      w[i] = (long double)(n * (n-1) / 2 - inv[i])/tot;
    long long le = 0, ri = 10000000000;
    long long ans = 0;
    long double best = calc2(0);
    while (ri-le > 2) {
      long long mid1 = (le + le + ri) / 3, mid2 = (le + ri + ri) / 3;
      long double val1 = calc2(mid1), val2 = calc2(mid2);
      if (val1 < best)
        ans = mid1, best = val1;
      if (val2 < best)
        ans = mid2, best = val2;
      if (val1 < val2)
        ri = mid2;
      else
        le = mid1;
    }
    for (long long i = le; i <= ri; ++i) {
      long double cur = calc2(i);
      if (cur < best)
        ans = i, best = cur;
    }
    for (int i = 0; i < m; ++i) {
      printf("%d%c", min(r[i], max(l[i], (int)(ans * w[i] + 0.5))), i == m-1 ? '\n' : ' ');
    }
  }
  return 0;
}