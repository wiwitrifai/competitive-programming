#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long inf = 1e18 + 18;

string awal = "What are you doing while sending \"";
string tengah = "\"? Are you busy? Will you send \"";
string akhir = "\"?";
string basis = "What are you doing at the end of the world? Are you busy? Will you save us?";
long long f[N];

char get(int n, long long k) {
  if (k <= 0) return '.';
  if (f[n] < k) return '.';
  if (n == 0) {
    return basis[k-1];
  }
  if (k <= awal.size())
    return awal[k-1];
  k -= awal.size();

  if (k <= f[n-1])
    return get(n-1, k);
  k -= f[n-1];

  if (k <= tengah.size())
    return tengah[k-1];
  k -= tengah.size();

  if (k <= f[n-1])
    return get(n-1, k);
  k -= f[n-1];

  if (k <= akhir.size())
    return akhir[k-1];
  k -= akhir.size();

  return '.';
}

int main() {
  f[0] = basis.size();
  for (int i = 1; i < N; i++) {
    f[i] = 2LL * f[i-1] + awal.size() + tengah.size() + akhir.size();
    f[i] = min(f[i], inf); 
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int n;
    long long k;
    cin >> n >> k;
    cout << get(n, k);
  }
  cout << endl;
  return 0;
}