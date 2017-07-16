
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long inf = 1e12;

vector< long long > get(const vector< long long > & v, long long low, long long hig, long long k) {
  if (1LL * v.size() * (v.size() + 1) <= 4LL * k) {
    vector< long long > ret;
    for (long long i = 0; i < v.size(); i++) {
      ret.push_back(v[i]);
      for (long long j = 0; j < i; j++)
        ret.push_back(v[i] - v[j]);
    }
    return ret;
  }
  long long lo = low, hi = hig;
  while (lo < hi) {
    long long sum = lo + hi;
    long long mid = sum < 0 ? - ((-sum + 1) / 2) : sum / 2;
    long long cnt = 0;
    multiset< long long > mul;
    mul.insert(0);
    for (long long x : v) {
      for (auto it = mul.begin(); it != mul.end(); it++) {
        if (x-*it < mid) break;
        cnt++;
      }
      if (cnt > k) break;
      mul.insert(x);
    }
    if (cnt > k)
      lo = mid + 1;
    else
      hi = mid;
  }
  long long up = lo;
  lo = low, hi = hig;
  while (lo < hi) {
    long long sum = lo + hi;
    long long mid = sum < 0 ? - ((-sum) / 2) : (sum + 1) / 2;
    long long cnt = 0;
    multiset< long long > mul;
    mul.insert(0);
    for (long long x : v) {
      for (auto it = mul.begin(); it != mul.end(); it++) {
        if (x+*it > mid) break;
        cnt++;
      }
      if (cnt > k) break;
      mul.insert(-x);
    }
    if (cnt > k)
      hi = mid - 1;
    else
      lo = mid;
  }
  assert(lo < up);
  multiset<long long> neg, pos;
  neg.insert(0);
  pos.insert(0);
  vector< long long > ret;
  long long cpos = 0, cneg = 0;
  for (long long x : v) {
    for (auto it = pos.begin(); it != pos.end(); it++) {
      if (x-*it < up) break;
      cpos++;
      ret.push_back(x-*it);
    }
    for (auto it = neg.begin(); it != neg.end(); it++) {
      if (x+*it > lo) break;
      cneg++;
      ret.push_back(x+*it);
    }
    pos.insert(x);
    neg.insert(-x);
  }
  long long all = 1LL * v.size() * (v.size() + 1)/2;
  while (((cpos < k) || (cneg < k)) && (cpos + cneg < all)) {
    if (cpos < k)
      ret.push_back(up - 1), cpos++;
    if ((cneg < k) && (cpos + cneg) < all)
      ret.push_back(lo + 1), cneg++;
  }
  return ret;
}

vector< long long > a, b;

int main() {
  time_t startt = clock();
  int tt;
  scanf("%d", &tt);
  for (int tc = 1; tc <= tt; tc++) {
    long long n, k, A1, B1, C, D, E1, E2, F;
    cin >> n >> k >> A1 >> B1 >> C >> D >> E1 >> E2 >> F;
    a.clear(); b.clear();
    for (long long x = A1, y = B1, s = 0, r = 0; a.size() < n; ) {
      a.push_back(r ? -x : x);
      b.push_back(s ? -y : y);
      long long nx, ny, ns, nr;
      nx = (C * x + D * y + E1) % F;
      ny = (D * x + C * y + E2) % F;
      nr = (C * r + D * s + E1) % 2;
      ns = (D * r + C * s + E2) % 2;
      x = nx, y = ny, s = ns, r = nr; 
    }
    vector< long long > sa, sb;
    long long ssa = 0, ssb = 0;
    for (long long x : a) {
      ssa += x;
      sa.push_back(ssa);
    }
    for (long long x : b)
      ssb += x, sb.push_back(ssb);
    vector< long long > a = get(sa, -inf, inf, N), b = get(sb, -inf, inf, N);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    long long lo = -1e18, hi = 1e18;
    while (lo < hi) {
      long long sum = (lo + hi);
      long long mid = sum < 0 ? - ((-sum) / 2) : (sum + 1) / 2;
      long long cnt = 0;
      for (long long v : a) {
        if (v == 0) {
          if (mid <= 0)
            cnt += b.size();
        }
        else if (v > 0) {
          long long mi = mid >= 0 ? (mid + v - 1)/v : - ((-mid)/v);
          cnt += b.end() - lower_bound(b.begin(), b.end(), mi);
        }
        else {
          v = -v;
          long long cur = -mid;
          long long mi = cur >= 0 ? (cur)/v : - ((-cur + v- 1)/v);
          cnt += upper_bound(b.begin(), b.end(), mi) - b.begin();
        }
        if (cnt > k) break;
      }
      if (cnt >= k)
        lo = mid;
      else
        hi = mid - 1;
    }
    printf("Case #%d: %lld\n", tc, lo);
    cerr << "~ #" << tc << " done! time : " << (double)(clock()-startt) * 1000/CLOCKS_PER_SEC << " ms" << endl;
  }
  return 0;
}