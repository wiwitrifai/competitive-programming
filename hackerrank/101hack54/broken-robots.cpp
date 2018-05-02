#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

const int N = 2e5 + 5, S = sqrt(N), mod = 1e9 + 7;

int cnt[N];
int ev[N];
vector<int> st[S];
long long fac[N], inv[N];

long long powmod(long long b, long long p) {
    long long r = 1;
    for (; p; p >>= 1, b = b * b % mod)
        if (p & 1)
            r = b * r % mod;
    return r;
}

long long C(int n, int k) {
    if (k < 0 || n < k) return 0;
    return (fac[n] * inv[k] % mod) * inv[n-k] % mod;
}

// Complete the expectedNumberOfBurningCandles function below.
int expectedNumberOfBurningCandles(int n, int m, int k) {
    // Take the description of the robots from standard input and return the integer answer
    fac[0] = inv[0] = 1;
    for (int i = 1; i < N; ++i)
        fac[i] = fac[i-1] * i % mod, inv[i] = powmod(fac[i], mod-2);
    for (int i = 0; i < m; ++i) {
        int a, d;
        scanf("%d %d", &a, &d);
        if (d >= S)
            for (int j = a; j <= n; j += d)
                ++cnt[j];
        else
            st[d].push_back(a);
    }
    for (int d = 1; d < S; ++d) {
        fill(ev, ev+n+1, 0);
        for (int a : st[d])
            ++ev[a];
        for (int i = 1; i <= n; ++i) {
            if (i + d <= n)
                ev[i+d] += ev[i];
            cnt[i] += ev[i];
        }
    }
    long long ans = 0;
    long long tot = C(m, k);
    for (int i = 1; i <= n; ++i) {
        int sisa = m - cnt[i];
        ans = (ans + tot - C(sisa, m-k)) % mod; 
    }
    ans = ans * powmod(tot, mod - 2) % mod;
    if (ans < 0) ans += mod;
    // cerr << ans << endl;
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nmk_temp;
    getline(cin, nmk_temp);

    vector<string> nmk = split_string(nmk_temp);

    int n = stoi(nmk[0]);

    int m = stoi(nmk[1]);

    int k = stoi(nmk[2]);

    int result = expectedNumberOfBurningCandles(n, m, k);

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
