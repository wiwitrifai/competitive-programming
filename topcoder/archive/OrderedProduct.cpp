#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

long long powmod(long long b, long long p) {
	long long ret = 1;
	for (; p; p >>= 1, b = b * b % mod)
		if (p & 1) ret = ret * b % mod;
	return ret;
}
const int N = 5050;
long long fac[N], inv[N];

long long C(long long n, long long k) {
	if (n < k || n < 0)
		return 0;
	return ((fac[n] * inv[k]) % mod) * inv[n-k] % mod;
}
long long dp[55][5050];

class OrderedProduct {
public:
	int count(vector <int> a) {
		fac[0] = inv[0] = 1;
		for (int i = 1; i < N; i++) {
			fac[i] = fac[i-1] * i % mod;
			inv[i] = powmod(fac[i], mod-2);
		}
		int sum = 0, n = a.size();
		for (int v : a)
			sum += v;
		dp[0][0] = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= sum; j++) {
				if (dp[i][j] == 0) continue;
				long long now = dp[i][j];
				for (int z = 0; z <= a[i]; z++) {
					long long cur = now * (j == 0 ? (z == 0) : C(z+j-1, j-1)) % mod;
					if (cur == 0) continue;
					int r = a[i]-z;
					for (int y = 0; y <= r; y++) {
						long long wew = cur * (y == 0 ? (r == 0) : C(r-1, y-1)) % mod;
						wew = wew * C(y + j, y) % mod;
						dp[i+1][y+j] += wew;
						if (dp[i+1][y+j] >= mod)
							dp[i+1][y+j] -= mod;
					}
				}
			}
		}
		long long ans = 0;
		for (int i = 0; i <= sum; i++) {
			ans += dp[n][i];
			if (ans >= mod) ans -= mod;
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
		cout << "Testing OrderedProduct (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1490435126;
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
		OrderedProduct _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int a[] = {1, 1};
				_expected = 3;
				_received = _obj.count(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 1:
			{
				int a[] = {2};
				_expected = 2;
				_received = _obj.count(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 2:
			{
				int a[] = {1, 1, 1, 1, 1};
				_expected = 541;
				_received = _obj.count(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 3:
			{
				int a[] = {23, 49, 12};
				_expected = 316396073;
				_received = _obj.count(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			case 4:
			{
				int a[] = {2, 5, 4, 2, 3, 1, 3, 1, 4, 6};
				_expected = 225466557;
				_received = _obj.count(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}
			/*case 5:
			{
				int a[] = ;
				_expected = ;
				_received = _obj.count(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int a[] = ;
				_expected = ;
				_received = _obj.count(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int a[] = ;
				_expected = ;
				_received = _obj.count(vector <int>(a, a+sizeof(a)/sizeof(int))); break;
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
