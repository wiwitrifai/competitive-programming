#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7, N = 2505, M = 2500 * 100 + 5;

int idx[256];
int first_occ[256], last_occ[256];
long long fac[M], inv[M];
int dp[N][N];

long long powmod(long long b, long long p) {
	long long r = 1;
	for (; p; p >>= 1, b = b * b % mod)
		if (p & 1)
			r = r * b % mod;
	return r;
}

long long C(int n, int k) {
	if (k < 0 || n < k)
		return 0;
	return (fac[n] * inv[k] % mod) * inv[n - k] % mod;
}

struct MonotoneStrings {
	int count(int S, string pattern) {
		fac[0] = inv[0] = 1;
		for (int i = 1; i < M; ++i) {
			fac[i] = fac[i-1] * i % mod;
			inv[i] = powmod(fac[i], mod - 2);
		}
		memset(idx, -1, sizeof idx);
		memset(first_occ, -1, sizeof first_occ);
		memset(last_occ, -1, sizeof last_occ);
		int n = pattern.size();
		int v = min(S, 62);
		int now = 0;
		for (char c = 'a'; c <= 'z'; ++c)
			idx[c] = now++;
		for (char c = 'A'; c <= 'Z'; ++c)
			idx[c] = now++;
		for (char c = '0'; c <= '9'; ++c)
			idx[c] = now++;
		for (int i = 0; i < n; ++i) {
			int p = idx[pattern[i]];
			if (p == -1) continue;
			if (first_occ[p] == -1)
				first_occ[p] = i;
			last_occ[p] = i;
		}
		for (int i = 0; i < v; ++i) {
			if (first_occ[i] == -1) continue;
			for (int j = i+1; j < v; ++j) {
				if (first_occ[j] == -1) continue;
				if (first_occ[i] <= last_occ[j] && first_occ[j] <= last_occ[i]) {
					return 0;
				}
			}
		}
		vector<int> dist;
		int cur = 0;
		for (int i = 0; i < n; ++i) {
			int p = idx[pattern[i]];
			if (p != -1) {
				dist.push_back(cur);
				cur = 0;
				i = last_occ[p];
			} else {
				if (pattern[i] == '?')
					cur += 1;
				else if (pattern[i] == '-')
					cur += 10;
				else
					cur += 100;
			}
		}
		dist.push_back(cur);
		if (dist.size() == 1)
			--dist[0];
		dp[0][0] = 1;
		for (int i = 0; i < (int)dist.size(); ++i) {
			int min_pick = (i == 0 || (i + 1) == (int)dist.size()) ? 0 : 1;
			int max_pick = min_pick + dist[i];
			for (int j = 0; j < S; ++j) {
				int limit = min(j, max_pick);
				for (int pick = min_pick; pick <= limit; ++pick) {
					dp[i+1][j] = (dp[i+1][j] + C(max_pick, pick) * dp[i][j-pick]) % mod;
				}
			}
		}
		long long ans = 0;
		int k = dist.size() - 1;
		for (int i = max(k, 1); i <= S; ++i) {
			int add = i - k;
			long long mul = fac[S-k] * inv[S - k - add] % mod;
			ans = (ans + 1LL * dp[k+1][i-1] * mul) % mod;
		}
		return ans;
	}
};

// BEGIN CUT HERE
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc == 1) 
	{
		cout << "Testing MonotoneStrings (850.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1629564532;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 850.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		MonotoneStrings _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int S = 26;
				string pattern = "te?th";
				_expected = 0;
				_received = _obj.count(S, pattern); break;
			}
			case 1:
			{
				int S = 1;
				string pattern = "++++++++++";
				_expected = 1;
				_received = _obj.count(S, pattern); break;
			}
			case 2:
			{
				int S = 4;
				string pattern = "++++++++++++++++++++";
				_expected = 952039775;
				_received = _obj.count(S, pattern); break;
			}
			case 3:
			{
				int S = 370;
				string pattern = "?4?";
				_expected = 136531;
				_received = _obj.count(S, pattern); break;
			}
			case 4:
			{
				int S = 30;
				string pattern = "ll??as";
				_expected = 786;
				_received = _obj.count(S, pattern); break;
			}
			/*case 5:
			{
				int S = ;
				string pattern = ;
				_expected = ;
				_received = _obj.count(S, pattern); break;
			}*/
			/*case 6:
			{
				int S = ;
				string pattern = ;
				_expected = ;
				_received = _obj.count(S, pattern); break;
			}*/
			/*case 7:
			{
				int S = ;
				string pattern = ;
				_expected = ;
				_received = _obj.count(S, pattern); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (_received == _expected)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
