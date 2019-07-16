#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5, mod = 1e9 + 7;

long long powmod(long long b, long long p) {
	long long r = 1;
	for (; p; p >>= 1, b = b * b % mod)
		if (p & 1)
			r = r * b% mod;
	return r;
}

long long fac[N], inv[N];

long long C(int n, int k) {
	if (n < 0 || k < 0 || k > n)
		return 0;
	return (fac[n] * inv[k] % mod) * inv[n-k] % mod;
}

class HomeAwayLeague {
public:
	int matches(int x) {
		fac[0] = inv[0] = 1;
		for (int i = 1; i < N; ++i) {
			fac[i] = 1LL * i * fac[i-1] % mod;
		}
		inv[N-1] = powmod(fac[N-1], mod - 2);
		for (int i = N-2; i > 0; --i) {
			inv[i] = 1LL * inv[i+1] * (i+1) % mod;
		}
		long long h = x/2;
		long long ans = 0;
		for (int i = 0; i <= h; ++i) {
			long long cur = h - i;
			long long now = fac[cur];
			now = now * C(h, i) % mod;
			if (i & 1)
				ans = (ans - now) % mod;
			else
				ans = (ans + now) % mod;
		}
		ans %= mod;
		if (ans < 0)
			ans += mod;
		ans = (1LL * ans * fac[h]) % mod;
		ans = (1LL * ans * C(x, h)) % mod;
		ans %= mod;
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
		cout << "Testing HomeAwayLeague (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1560387870;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		HomeAwayLeague _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x = 4;
				_expected = 12;
				_received = _obj.matches(x); break;
			}
			case 1:
			{
				int x = 8;
				_expected = 15120;
				_received = _obj.matches(x); break;
			}
			case 2:
			{
				int x = 500000;
				_expected = 0;
				_received = _obj.matches(x); break;
			}
			/*case 3:
			{
				int x = ;
				_expected = ;
				_received = _obj.matches(x); break;
			}*/
			/*case 4:
			{
				int x = ;
				_expected = ;
				_received = _obj.matches(x); break;
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
