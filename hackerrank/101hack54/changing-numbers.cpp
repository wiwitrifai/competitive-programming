#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);


const int N = 2e6 + 5, mod = 1e9 + 7;

long long powmod(long long b, long long p) {
    long long r = 1;
    for (; p; p >>= 1, b = b * b % mod)
        if (p & 1)
            r = r * b % mod;
    return r;
}

vector<int> fact[N];
long long fac[N], inv[N];
int nprim[N], sum[N], lp[N];
long long ans[N];

long long C(int n, int k) {
    if (k < 0 || n < k) return 0;
    return (fac[n] * inv[k] % mod) * inv[n-k] % mod;
}

// Complete the distinctNumbers function below.
int distinctNumbers(int n, int k) {
    // Return the number of distinct numbers you can get and return the answer modulo 1000000007
       fac[0] = inv[0] = 1;
    for (int i = 1; i < N; ++i) {
        fac[i] = fac[i-1] * i % mod;
    }
    inv[N-1] = powmod(fac[N-1], mod-2);
    for (int i = N-2; i > 0; --i) {
        inv[i] = inv[i+1] * (i+1) % mod;
        assert((inv[i] * fac[i] % mod) == 1);
    }
    int all = 0;
    for (int i = 2; i <= n; ++i) {
        if (lp[i]) continue;
        ++all;
        for (int j = i; j <= n; j += i)
            if (lp[j] == 0) lp[j] = i;
    }
    nprim[1] = sum[1] = 0;
    for (int i = 2; i <= n; ++i) {
        int last = lp[i];
        int now = i, cnt = 0;
        while ((now % last) == 0) {
            now /= last;
            ++cnt;
        }
        nprim[i] = nprim[now] + 1;
        sum[i] = sum[now] + cnt;
    }
    // cerr << all << endl;
    for (int i = 1; i <= n; ++i) {
        int np = all - nprim[i];
        int used = sum[i];
        if (used > k) continue;
        for (int j = i; j <= n; j += i) {
            int sisa = k - used;
            // cerr << i << " " << j << " " << sisa << " " << np << " " << C(sisa + np, np) << endl;
            ans[j] = (ans[j] + C(sisa + np, np)) % mod;
        }
    }
    long long tot = 0;
    for (int i = 1; i <= n; ++i) {
        tot = (tot + i * ans[i]) % mod;
        // cerr << i << " " << ans[i] << endl;
    }
    return tot;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    int result = distinctNumbers(n, k);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
