#include <bits/stdc++.h>

using namespace std;

vector< int > bx, by;
long long dp[66][66][2][2];
long long solve(int ix, int iy, int lx, int ly) {
	if (ix == bx.size()) {
		if (iy == by.size()) {
			return 1;
		}
		return 0;
	}
	long long & ret = dp[ix][iy][lx][ly];
	if (ret != -1) return ret;
	ret = 0;
	// one
	bool ok = 1;
	if (lx == 0 && bx[ix] == 0)
		ok = 0;
	if (iy == by.size()) {
		if (ok) ret += solve(ix+1, iy, lx, ly);
	}
	else {
		if (ly == 0 && by[iy] == 0)
			ok = 0;
		if (ok) ret += solve(ix+1, iy+1, lx, ly);
	}
	// zero
	ok = 1;
	if ((int)by.size()-iy == (int)bx.size()-ix)
		ret += solve(ix+1, iy+1, lx | (bx[ix] == 1), ly | (by[iy] == 1));
	else
		ret += solve(ix+1, iy, lx | (bx[ix] == 1), ly);
	return ret;
}

class PrimeStrings {
public:
	long long getCount(long long x, long long y, int k) {
		int py = 63-__builtin_clzll(y), px = 63-__builtin_clzll(x);
		if (py+k > px) return x;
		long long ma = (1LL << (py+k+1)) - 1;
		x = min(x, ma);
		long long ans = (1LL << (py+k)) - 1;
		long long now = x;
		bx.clear(); by.clear();
		while (now) {
			bx.push_back(now & 1);
			now >>= 1;
		}
		now = y;
		while (now) {
			by.push_back(now & 1);
			now >>= 1;
		}
		reverse(bx.begin(), bx.end());
		reverse(by.begin(), by.end());
		assert(by.size() + k == bx.size());
		memset(dp, -1, sizeof dp);
		ans += solve(1, 1, 0, 0);
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
		cout << "Testing PrimeStrings (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1491279275;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		PrimeStrings _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				long long x = 2LL;
				long long y = 1LL;
				int k = 1;
				_expected = 2LL;
				_received = _obj.getCount(x, y, k); break;
			}
			case 1:
			{
				long long x = 6LL;
				long long y = 2LL;
				int k = 1;
				_expected = 4LL;
				_received = _obj.getCount(x, y, k); break;
			}
			case 2:
			{
				long long x = 6LL;
				long long y = 1LL;
				int k = 3;
				_expected = 6LL;
				_received = _obj.getCount(x, y, k); break;
			}
			case 3:
			{
				long long x = 31LL;
				long long y = 6LL;
				int k = 2;
				_expected = 20LL;
				_received = _obj.getCount(x, y, k); break;
			}
			case 4:
			{
				long long x = 413LL;
				long long y = 34LL;
				int k = 2;
				_expected = 130LL;
				_received = _obj.getCount(x, y, k); break;
			}
			case 5:
			{
				long long x = 1000000000LL;
				long long y = 1000000000LL;
				int k = 5;
				_expected = 1000000000LL;
				_received = _obj.getCount(x, y, k); break;
			}
			case 6:
			{
				long long x = 549755813602LL;
				long long y = 8369864093LL;
				int k = 5;
				_expected = 178429547459LL;
				_received = _obj.getCount(x, y, k); break;
			}
			/*case 7:
			{
				long long x = LL;
				long long y = LL;
				int k = ;
				_expected = LL;
				_received = _obj.getCount(x, y, k); break;
			}*/
			/*case 8:
			{
				long long x = LL;
				long long y = LL;
				int k = ;
				_expected = LL;
				_received = _obj.getCount(x, y, k); break;
			}*/
			/*case 9:
			{
				long long x = LL;
				long long y = LL;
				int k = ;
				_expected = LL;
				_received = _obj.getCount(x, y, k); break;
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
