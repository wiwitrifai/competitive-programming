#include <bits/stdc++.h>

using namespace std;

const int N = 2002, mod = 1e9 + 7;

long long powmod(long long b, long long p) {
	long long r = 1;
	for (; p; p >>= 1, b = b * b % mod)
		if (p & 1)
			r = r * b % mod;
	return r;
}

long long inv[3 * N];
long long dp1[N][N], dp2[N+N][N];
long long sum1[N+N+N], sum2[N+N+N];


class PBG {
public:
	int findEV(int P, int B, int G) {
		for (int i = 1; i < N * 3; ++i)
			inv[i] = powmod(i, mod-2);
		dp1[P][G] = 1;
		for (int p = P; p >= 1; --p) {
			for (int g = G; g >= 0; --g) {
				long long cur = dp1[p][g];
				if (cur == 0) continue;
				long long probg = 0;
				if (g > 0) {
					probg = 1LL * g * (g-1) % mod;
					probg = probg * inv[p+g] % mod;
					probg = probg * inv[p+g-1] % mod;
					dp1[p][g-1] = (dp1[p][g-1] + probg * cur) % mod;
				}
				if (p > 0) {
					long long probp = (1 + mod - probg) % mod;
					dp1[p-1][g] = (dp1[p-1][g] + probp * cur) % mod;
				}
				cur = cur * p % mod;
				cur = cur * inv[P] % mod;
				sum1[P + G - p - g] = (sum1[P + G - p - g] + cur) % mod;
			}
		}
		dp2[P+G][B] = 1;
		for (int p = P+G; p >= 1; --p) {
			for (int b = B; b >= 0; --b) {
				long long cur = dp2[p][b];
				if (cur == 0) continue;
				long long probp = 0;
				if (p+b > 1) {
					probp = 1LL * p * (p-1) % mod;
					probp = probp * inv[p+b] % mod;
					probp = probp * inv[p+b-1] % mod;
				}
				if (p > 0)
					dp2[p-1][b] = (dp2[p-1][b] + probp * cur) % mod;
				if (b > 0) {
					long long probb = (1 + mod - probp) % mod;
					dp2[p][b-1] = (dp2[p][b-1] + probb * cur) % mod;
				}
				sum2[P + G + B - p - b] = (sum2[P + G + B - p - b] + cur * sum1[P+G - p]) % mod;
			}
		}
		long long ans = 0;
		for (int i = 0; i < P + G + B; ++i) {
			sum2[i] = (sum2[i] + mod - sum2[i+1]) % mod;
			ans = (ans + sum2[i] * (P + G + B - i)) % mod;
		}
		if (ans < 0)
			ans += mod;
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
		cout << "Testing PBG (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1570720194;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		PBG _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int P = 5;
				int B = 0;
				int G = 0;
				_expected = 3;
				_received = _obj.findEV(P, B, G); break;
			}
			case 1:
			{
				int P = 1;
				int B = 1;
				int G = 1;
				_expected = 333333338;
				_received = _obj.findEV(P, B, G); break;
			}
			case 2:
			{
				int P = 1;
				int B = 3;
				int G = 0;
				_expected = 1;
				_received = _obj.findEV(P, B, G); break;
			}
			case 3:
			{
				int P = 2;
				int B = 3;
				int G = 4;
				_expected = 672193888;
				_received = _obj.findEV(P, B, G); break;
			}
			case 4:
			{
				int P = 1;
				int B = 0;
				int G = 3;
				_expected = 333333339;
				_received = _obj.findEV(P, B, G); break;
			}
			case 5:
			{
				int P = 1;
				int B = 0;
				int G = 0;
				_expected = 1;
				_received = _obj.findEV(P, B, G); break;
			}
			case 6:
			{
				int P = 2000;
				int B = 2000;
				int G = 2000;
				_expected = 246923693;
				_received = _obj.findEV(P, B, G); break;
			}
			/*case 7:
			{
				int P = ;
				int B = ;
				int G = ;
				_expected = ;
				_received = _obj.findEV(P, B, G); break;
			}*/
			/*case 8:
			{
				int P = ;
				int B = ;
				int G = ;
				_expected = ;
				_received = _obj.findEV(P, B, G); break;
			}*/
			/*case 9:
			{
				int P = ;
				int B = ;
				int G = ;
				_expected = ;
				_received = _obj.findEV(P, B, G); break;
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
