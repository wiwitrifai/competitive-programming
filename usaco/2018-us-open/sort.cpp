#include <bits/stdc++.h>

using namespace std;

void open(string s) {
#ifndef LOCAL
  freopen((s + ".in").c_str(), "r", stdin); 
  freopen((s + ".out").c_str(), "w", stdout);
#endif
}

void close() {
#ifndef LOCAL
  fclose(stdin);
  fclose(stdout);
#endif
}

const int N = 1e5 + 5;

int bit[N];
int get(int x) {
  int r = 0;
  for (; x < N; x += x & -x)
    r += bit[x];
  return r;
}
void upd(int x, int v) {
  for (; x; x -= x & -x)
    bit[x] += v;
}
int a[N], last[N], b[N];
vector<int> rem[N];

int main() {
  open("sort");
  int n;
  scanf("%d", &n);
  vector<int> val;
  for (int i = 0; i < n; ++i) {
    scanf("%d", a+i);
    val.push_back(a[i]);
  }
  sort(val.begin(), val.end());
  val.erase(unique(val.begin(), val.end()), val.end());
  for (int i = 0; i < n; ++i)
    a[i] = lower_bound(val.begin(), val.end(), a[i]) - val.begin()+1, b[i] = a[i];
  long long ans = 0;
  sort(b, b+n);
  for (int i = 0; i < n; ++i)
    if (a[i] == b[i]) ++ans;
    else break;
  for (int i = 0; i < n; ++i)
    last[a[i]] = i;
  for (int i = 0; i < val.size(); ++i)
    last[i+1] = max(last[i], last[i+1]);
  for (int i = 0; i < n; ++i) {
    if (last[a[i]-1] > i) {
      ans += n-i;
      rem[last[a[i]-1]].push_back(a[i]);
    }
  }
  for (int i = n-1; i >= 0; --i) {
    upd(a[i], 1);
    for (int x : rem[i])
      ans -= get(x);
  }
  printf("%lld\n", ans);
  close();
  return 0;
}