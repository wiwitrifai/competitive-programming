// for observation only

#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 1;

int a[N], cnt[N];
int calc[N];
bool isp[N];
vector<int> prime;

int main() {
  set<int> st;
  for (int i = 0; i < N; ++i)
    a[i] = i;
  for (int i = 2; i < N; ++i) {
    if (isp[i]) continue;
    prime.push_back(i);
    for (int j = i; j < N; j += i) {
      isp[j] = 1;
      int now = a[j];
      while ((now % i) == 0)
        now /= i;
      now *= i;
      a[j] = now;
      ++cnt[j];
    }
  }

  for (int i = 2; i < N; ++i) {
    st.insert(a[i]);
    calc[cnt[i]]++;
  }
  for (int i = 0; i < 10; ++i)
    cerr << i << " cnt " << calc[i] << endl;
  long long now = 1;
  for (int i = 0; i < 30; ++i) {
    now *= prime[i];
    cerr << i << " " << now << endl;
  }
  cerr << prime.size() << endl;
  cerr << st.size() << endl;
  return 0;
}