using namespace std;

const int N = 55;
const long long inf = 1e10 + 7;

long long cnt[N];
string get(int n, long long k) {
  if (n < 3) {
    if (k != 1) return "-1";
    string ret = "a";
    ret[0] += n;
    return ret;
  }
  if (k <= cnt[n-1])
    return get(n-1, k);
  k -= cnt[n-1];
  if (k <= cnt[n-2])
    return get(n-2, k);
  k -= cnt[n-2];
  return get(n-3, k);
}

int main() {
  cnt[0] = cnt[1] = cnt[2] = 1;
  for (int i = 3; i < N; i++) {
    cnt[i] = min(cnt[i-1] + cnt[i-2] + cnt[i-3], inf);
  }
  long long n, k;
  cin >> n >> k;
  cout << get(n, k) << endl;
  return 0;
}