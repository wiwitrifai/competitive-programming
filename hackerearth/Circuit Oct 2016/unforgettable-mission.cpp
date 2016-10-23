  #include <bits/stdc++.h>

  using namespace std;

  const int N = 102;
  const long long inf = 1e17;
  const int threshold = 400000;
  long long x;
  int n, a[N * N / 4][N][N];

  long long rnd() {
    x = (x * 37 + 10007) % 1000000007;
    return x;
  }
  long long sign() {
    if(rnd() > 500000003) return +1;
    return -1;
  }
  long long rng(){
    long long value = rnd();
    value *= sign();
    return value;
  }
  void init(){
    int nn = n * n / 4;
    for(int i = 0; i < n; i++)
      for(int j = i + 1; j < n; j++)
        for(int k = 0; k <= nn; k++)
          a[j][i][k] = a[i][j][k] = rng();
  }

  long long ans;
  bitset< N > b;
  long long sum[N];
  int cntr;

  void process(bitset< N > cur) {
    long long all = 0;
    memset(sum, 0, sizeof sum);
    int c = cur.count();
    c = c * (n-c);
    for (int i = 0; i < n; i++) if (cur[i]) {
      for (int j = i+1; j < n; j++) if (cur[j]) {
        sum[i] += a[i][j][c];
        sum[j] += a[i][j][c];
        all += a[i][j][c];
      }
    }
    while (cntr++ < threshold) {
      if (all > ans) {
        ans = all;
        b = cur;
      }
      int mi = -1;
      for (int i = 0; i < n; i++) if (cur[i]) {
        if (mi == -1 || sum[mi] > sum[i])
          mi = i;
      }
      if (mi == -1)
        break;
      vector< int > cand;
      for (int i = 0; i < n; i++) if (cur[i] && sum[i] == sum[mi])
        cand.push_back(i);
      bool ok = false;
      for (int v : cand) {
        for (int i = 0; i < n; i++) if (!cur[i]) {
          long long now = all - sum[v];
          for (int j = 0; j < n; j++) if (cur[j] && j != v) {
            now += a[i][j][c];
          }
          if (now > all) {
            ok = true;
            cur[v] = 0;
            for (int j = 0; j < n; j++) if (cur[j]) {
              sum[j] -= a[v][j][c];
              sum[i] += a[i][j][c];
            }
            sum[v] = 0;
            cur[i] = 1;
            all = now;
            break;
          }
        }
      }
      if (!ok)
        break;
    }
  }

  int main() {
    cin >> n >> x;
    init();
    ans = 0;
    b.reset();
    cntr = 0;
    for (int i = 2; i <= n; i++) {
      bitset< N > cur;
      cur.reset();
      for (int j = 0; j < i; j++)
        cur[j] = 1;
      process(cur);
    }
    while (cntr < threshold) {
      bitset< N > cur;
      cur.reset();
      long long now;
      for (int i = 0; i < n; i++) {
        if ((i % 29) == 0) {
          now = rnd();
        }
        cur[i] = now & 1;
        now <<= 1;
      }
      process(cur);
    }
    printf("%d\n", b.count());
    for (int i = 0; i < n; i++)
      if (b[i])
        printf("%d ", i+1);
      printf("\n");
    return 0;
  }