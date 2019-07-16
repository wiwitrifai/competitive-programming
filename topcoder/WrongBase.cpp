#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;

long long powmod(long long b, long long p) {
	b %= mod;
	long long r = 1;
	for (; p; p >>= 1, b = b * b % mod)
		if (p & 1)
			r = r * b % mod;
	return r;
}

class WrongBase {
public:
	int getSum(int g, int h, int a, int d, int n) {
		if (h == 0)
			return 0;
		int ss = sqrt(mod) + 2;
		map<int, int> mp;
		for (int i = 0; i < ss; ++i) {
			mp[powmod(g, i)] = i;
		}
		int r = -1;
		for (int i = 0; i < ss; ++i) {
			int gr = 1LL * powmod(g, mod-1 - ss * i) * h % mod;
			auto it = mp.find(gr);
			if (it != mp.end()) {
				r = it->second + i * ss;
				break;
			}
		}
		assert(r != -1);
		long long ans = 0;
		for (int i = 0; i < n; ++i) {
			ans = ans + powmod(a, r);
			if (ans >= mod)
				ans -= mod;
			a += d;
			// if (a >= mod)
			// 	a -= mod;
		}
		ans %= mod;
		if (ans < 0) ans += mod;
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
		cout << "Testing WrongBase (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1550802466;
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
		WrongBase _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int g = 3;
				int h = 7;
				int a = 3;
				int d = 3;
				int n = 5;
				_expected = 754398841;
				_received = _obj.getSum(g, h, a, d, n); break;
			}
			case 1:
			{
				int g = 3;
				int h = 332748118;
				int a = 100000000;
				int d = 100000000;
				int n = 1000000;
				_expected = 926938455 % mod;
				_received = _obj.getSum(g, h, a, d, n); break;
			}
			/*case 2:
			{
				int g = ;
				int h = ;
				int a = ;
				int d = ;
				int n = ;
				_expected = ;
				_received = _obj.getSum(g, h, a, d, n); break;
			}*/
			/*case 3:
			{
				int g = ;
				int h = ;
				int a = ;
				int d = ;
				int n = ;
				_expected = ;
				_received = _obj.getSum(g, h, a, d, n); break;
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
