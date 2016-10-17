#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 605;
const int MOD = 1e9 + 7;
 
struct polynomial {
    int deg;
    long long coeff[N];
 
    polynomial () {
      deg = 0;
      memset(coeff, 0, sizeof coeff);
    }
};
 
int t, n, q;
long long p[N];
polynomial f, g, h;
vector <long long> roots;
 
long long bigMod (long long a, long long e) {
  if (e == -1) e = MOD - 2;
  e %= (MOD - 1);
  long long r = 1; 
  while (e) {
    if (e & 1) r = (r * a) % MOD;
    a = (a * a) % MOD;
    e >>= 1;
  }
  return r;
}
 
void print (polynomial f) {
  cout << f.deg << endl;
  for (int i = f.deg; i >= 0; --i) cout << f.coeff[i] << " "; 
  cout << endl;
}
 
polynomial product (polynomial f, polynomial g) {
  polynomial h;
  h.deg = f.deg + g.deg;
 
  for (int i = 0; i <= f.deg; ++i)
    for (int j = 0; j <= g.deg; ++j)
      h.coeff[i + j] += f.coeff[i] * g.coeff[j], h.coeff[i + j] %= MOD;
 
  return h;
}
 
// Assuming deg f >= deg g
polynomial quotient (polynomial f, polynomial g) {
  polynomial q;
  q.deg = f.deg - g.deg;
 
  for (int i = q.deg; i >= 0; --i) {
      q.coeff[i] = (f.coeff[g.deg + i] * bigMod(g.coeff[g.deg], -1)) % MOD;
      for (int j = g.deg; j >= 0; --j) 
        f.coeff[i + j] -= q.coeff[i] * g.coeff[j], f.coeff[i + j] %= MOD;   
    }
 
    return q;
}
 
polynomial remainder (polynomial f, polynomial g) {
  if (f.deg < g.deg) return f;
 
    for (int i = f.deg - g.deg; i >= 0; --i) {
      long long c = (f.coeff[g.deg + i] * bigMod(g.coeff[g.deg], -1)) % MOD;
      for (int j = g.deg; j >= 0; --j) 
        f.coeff[i + j] -= c * g.coeff[j], f.coeff[i + j] %= MOD;   
    }
 
    f.deg = g.deg - 1;
    while (f.coeff[f.deg] == 0) --f.deg;
    f.deg = max(f.deg, 0);
    return f;
}
 
// Assuming deg f >= deg g
polynomial gcd (polynomial f, polynomial g) {
    if (g.deg == 0 and g.coeff[0] == 0) return f;
    return gcd(g, remainder(f, g));
}
 
// Cantor-Zassenhaus Algorithm
void findRoots (polynomial f) {
  if (f.deg == 1) {
    long long root = (-1 * f.coeff[0] * bigMod(f.coeff[1], -1)) % MOD;
    if (root < 0) root += MOD;
    roots.push_back(root);
    return;
  }
 
  while (true) {
    long long d = rand() % MOD;
    polynomial a, r;
    a.deg = 1, a.coeff[1] = 1, a.coeff[0] = d, r.coeff[0] = 1;
    int expo = MOD - 1;
 
    while (expo) {
      if (expo & 1) r = remainder(product(r, a), f);
      a = remainder(product(a, a), f);
      expo >>= 1;
    }
 
    --r.coeff[0];
    a = gcd(f, r);
 
    if (a.deg > 0 and a.deg < f.deg) {
      r = quotient(f, a);
      findRoots(a), findRoots(r);
      return;
    }
  }
}
 
int main (int argc, char const *argv[]) {
  scanf("%d", &t);
  for (int z = 1; z <= t; ++z) {
        scanf("%d %d", &n, &q);
        for (int i = 1; i <= n; ++i) scanf("%lld", p + i);
 
        if (t > 1) {
          if (n == 3) {
            long long abbcca = (((p[1] * p[1] - p[2]) % MOD) * bigMod(2, -1)) % MOD;
            long long abc = (((p[3] - p[1] * (p[2] - abbcca)) % MOD) * bigMod(3, -1)) % MOD;
            p[4] = (p[1] * p[3] + abc * p[1] - p[2] * abbcca) % MOD;
          } else if (n == 2) {
            long long ab = (((p[1] * p[1] - p[2]) % MOD) * bigMod(2, -1)) % MOD;
            p[3] = (p[1] * (p[2] - ab)) % MOD; 
            p[4] = (p[2] * p[2] - 2 * ab * ab) % MOD;
          } else if (n == 1) {
            p[2] = (p[1] * p[1]) % MOD;
            p[3] = (p[2] * p[1]) % MOD;
            p[4] = (p[3] * p[1]) % MOD;
          }
 
          while (q--) {
            long long x;
            scanf("%lld", &x);
            printf("%lld ", (p[x] + MOD) % MOD);
          }
 
          puts("");
          continue;
        }
 
        f.deg = n, f.coeff[n] = 1;
 
        // Extraction of polynomial from Newton sums 
        for (int i = n - 1; i >= 0; --i) {
            f.coeff[i] = 0;
            for (int j = n, k = n - i; k; --j, --k) {
                f.coeff[i] -= p[k] * f.coeff[j];
                f.coeff[i] %= MOD;
            }
            f.coeff[i] *= bigMod(n - i, - 1), f.coeff[i] %= MOD;
        }
 
        int pos = 0;
        while (f.coeff[pos] == 0) ++pos, roots.push_back(0);
        for (int i = pos; i <= f.deg; ++i) f.coeff[i - pos] = f.coeff[i];
        f.deg -= pos; 
 
      findRoots(f);
        
        while (q--) {
          long long x, res = 0; 
          scanf("%lld", &x);
          for (int i = 0; i < n; ++i) res += bigMod(roots[i], x), res %= MOD;
          printf("%lld ", (res + MOD) % MOD); 
        }
 
        puts("");
    }
    return 0;
} 