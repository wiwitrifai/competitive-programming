#include <bits/stdc++.h>

using namespace std;

int dp[1 << 23];
struct SplitMix64 {
    unsigned long long nextInt() {
        unsigned long long z = (x += 0x9E3779B97F4A7C15ULL);
        z = (z ^ (z >> 30)) * 0xBF58476D1CE4E5B9ULL;
        z = (z ^ (z >> 27)) * 0x94D049BB133111EBULL;
        return z ^ (z >> 31);
    }
    
    int random() {
        return 1 + (nextInt() >> 33);
    }
    
    unsigned long long x;
};

int mmask;
void init(const vector< vector<int> >& A) {
  int ma = max((int)A.size(), (int)A[0].size());
  mmask = 1;
  int k = 0;
  while (mmask <= ma) mmask <<= 1, ++k;
  int n = A.size(), m = A[0].size();
  memset(dp, 0, sizeof dp);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      dp[i | j] ^= A[i][j];
  for (int i = 0; i < k; ++i) {
    for (int mask = 0; mask < mmask; ++mask) {
      if (mask & (1 << i))
        dp[mask] ^= dp[mask ^ (1 << i)];
    }
  }
}

int query(int K) {
  return dp[K & (mmask-1)];
}

int main() {
    int N, M, Q; 
    SplitMix64 rng;
    
    cin >> N >> M >> Q >> rng.x;
    
    vector< vector<int> > A(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            A[i][j] = rng.random();
        }
    }
    
    init(A);
    
    unsigned long long hashSol = 0;
    
    for (int i = 1; i <= Q; i++) {
        hashSol ^= (unsigned long long)i * query(rng.random());
    }
    
    cout << hashSol << endl;
}
