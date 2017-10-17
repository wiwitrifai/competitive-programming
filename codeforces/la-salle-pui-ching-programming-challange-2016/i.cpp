#include <bits/stdc++.h>

using namespace std;



long long x, y, d; // ax + by = d
void extendedEuclidean(long long a, long long b) {
    if(b == 0) { x = 1; y = 0; d = a; return; } 
    extendedEuclidean(b, a % b); 
    long long xx, yy;
    xx = y;
    yy = x - (a/b)*y;
    x = xx; y = yy;
}

long long inverse(long long a, long long m) {
  extendedEuclidean(a, m);
  x %= m;
  if (x < 0) x += m;
  if ((a * x) % m == 1)
    return x;
  return -1; 
}

vector<long long> gauss(vector< vector<long long> >& A, long long m) {
    int n = A.size();

    for (int i=0; i<n; i++) {
        long long maxEl = A[i][i];
        int maxRow = i;
        for (int k=i+1; k<n; k++) {
            if (A[k][i] > maxEl) {
                maxEl = A[k][i];
                maxRow = k;
            }
        }
        for (int k=0; k<n+1;k++) {
            long long tmp = A[maxRow][k];
            A[maxRow][k] = A[i][k];
            A[i][k] = tmp;
        }
        long long inv = inverse(A[i][i], m);
        if (inv == -1)
          return vector<long long>();
        for (int j = 0; j < n+1; j++)
          A[i][j] = (A[i][j] * inv) % m;
        for (int k = 0; k < n; k++) {
            if (k == i) continue;
            if (A[k][i] == 0) continue;
            long long c = (-A[k][i]) % m;
            if (c < 0) c += m;
            for (int j=i; j<n+1; j++) {
                if (i==j) {
                    A[k][j] = 0;
                } else {
                    A[k][j] = (A[k][j] + c * A[i][j]) % m;
                }
            }
        }
    }
    vector<long long> x(n);
    for (int i = 0; i < n; i++) {
      x[i] = A[i][n] % m;
      if (x[i] < 0)
        x[i] += m;
    }
    return x;
}
const int N = 256;
char str[N];
int to[N];

bool cek(int ss) {
  for (int i = 0; i < 15; i++) {
    if (str[i] != '?') {
      if (ss != (str[i]-'0'))
        return false;
    }
    ss = to[ss-1];
  }
  return true;
}

int main() {
  scanf("%s", str);
  for (to[0] = 1; to[0] <= 4; to[0]++) {
    for (to[1] = 1; to[1] <= 4; to[1]++) {
      for (to[2] = 1; to[2] <= 4; to[2]++) {
        for (to[3] = 1; to[3] <= 4; to[3]++) {
          for (int ss = 1; ss <= 4; ss++) {
            if (!cek(ss)) continue;
            for (int m = 1; m <= 65535; m++) {
              bool ok = 1;
              vector<vector<long long> > A(4);
              for (int i = 0; i < 4; i++) {
                A[i].resize(5);
                A[i][4] = to[i] % m;
                int now = 1;
                for (int j = 0; j < 4; j++) {
                  A[i][3-j] = now;
                  now = (now * (i+1)) % m;
                }
              }
              vector<vector<long long> > B = A;
              vector<long long> x = gauss(A, m);
              ok &= x.size() == 4;
              for (int y : x)
                ok &= y < 1024;
              if (ok) {
                for (int i = 0; i < 4; i++)
                  printf("%d ", x[i]);
                printf("%d %d\n", m, ss);
                return 0;
              }
            }
          }
        }
      }
    }
  }
  puts("-1 -1 -1 -1 -1 -1");
  return 0;
}